#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include "linspace.h"
#include "gaussSeidel.h"
#include "jacobi.h"
#include "progonka.h"
#include "chebyshev.h"

int main() {
    unsigned int start_time, end_time, time_gs, time_j, time_ch; 

    std::vector<std::vector<double>> A = {{4, -1, 0, 0},
                                          {-1, 4, -1, 0},
                                          {0, -1, 4, -1},
                                          {0, 0, -1, 3}};
    std::vector<double> b = {30, 60, 70, 40}; 
    std::vector<double> x0 = {0, 0, 0, 0}; 

    std::vector<double> eps = linspace(1e-20, 0.1, 1000);

    std::vector<double> sol_gaussSeid, sol_jac, sol_progonka, sol_cheb;
    int iter_gs, iter_jac, iter_cheb;
    sol gs, j, ch;
    
    gs = gaussSeidel(A, b, x0, eps[0]);
    sol_gaussSeid = gs.solution;
    iter_gs = gs.num_iter;

    j = jacobi(A, b, x0, eps[0]);
    sol_jac = j.solution;
    iter_jac = j.num_iter;

    ch = chebyshev(A, b, eps[0]);
    sol_cheb = ch.solution;
    iter_cheb = ch.num_iter;

    sol_progonka = progonka(A, b);

    std::ofstream out;                  
    out.open("results.csv");        
    if (out.is_open())
    {
        out << "Gauss-Seidel\tJacobi\tchebyshev\ttprogonka" << std::endl;
        for (int i = 0; i < A.size(); ++i) {
            out << std::fixed << std::setprecision(20) << sol_gaussSeid[i] << '\t' << sol_jac[i];
            out << '\t' << sol_cheb[i] << '\t' << sol_progonka[i] << std::endl;
        }
    }
    out.close();

    std::ofstream out2;          
    out2.open("iterations_and_time.csv");
    if (out2.is_open()) {
        out2 << "Gauss-Seidel, iterations\tJacobi, iterations\tChebyshev, iterations\t";
        out2 << "Gauss-Seidel, time\tJacobi, time\tChebyshev, time\teps" << std::endl;
        for (int i = 0; i < eps.size(); i ++) {
            start_time = clock();
            gs = gaussSeidel(A, b, x0, eps[i]);
            sol_gaussSeid = gs.solution;
            iter_gs = gs.num_iter;
            end_time = clock();
            time_gs = end_time - start_time;

            start_time = clock();
            j = jacobi(A, b, x0, eps[i]);
            sol_jac = j.solution;
            iter_jac = j.num_iter;
            end_time = clock();
            time_j = end_time - start_time;

            start_time = clock();
            ch = chebyshev(A, b, eps[i], 1e+5);
            sol_cheb = ch.solution;
            iter_cheb = ch.num_iter;
            end_time = clock();
            time_ch = end_time - start_time;

            out2 << iter_gs << '\t' << iter_jac << '\t' << iter_cheb;
            out2 << '\t' << time_gs << '\t' << time_j << '\t' << time_ch << '\t' << eps[i] << std::endl;
        }
    }
    out2.close();

    return 0;
}
