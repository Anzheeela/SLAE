#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "linspace.h"
#include "gaussSeidel.h"
#include "jacobi.h"
#include "progonka.h"

int main() {
    unsigned int start_time, end_time, time_gs, time_j; 

    std::vector<std::vector<double>> A = {{4, -1, 0, 0},
                                          {-1, 4, -1, 0},
                                          {0, -1, 4, -1},
                                          {0, 0, -1, 3}}; 
    std::vector<double> b = {30, 60, 70, 40}; 
    std::vector<double> x0 = {0, 0, 0, 0}; 

    std::vector<double> eps = linspace(1e-20, 0.1, 1000);

    std::vector<double> sol_gaussSeid, sol_jac, sol_progonka;
    int iter_gs, iter_jac;
    sol gs, j;
    
    gs = gaussSeidel(A, b, x0, eps[0]);
    sol_gaussSeid = gs.solution;
    iter_gs = gs.num_iter;

    j = jacobi(A, b, x0, eps[0]);
    sol_jac = j.solution;
    iter_jac = j.num_iter;

    sol_progonka = progonka(A, b);

    std::ofstream out;                   
    out.open("results.csv");        
    if (out.is_open())
    {
        out << "Gauss-Seidel\tJacobi\tprogonka" << std::endl;
        for (int i = 0; i < A.size(); ++i) {
            out << std::fixed << std::setprecision(20) << sol_gaussSeid[i] << '\t' << sol_jac[i] << '\t' << sol_progonka[i] << std::endl;
        }
    }
    out.close();

    std::ofstream out2;          
    out2.open("iterations_and_time.csv");
    if (out2.is_open()) {
        out2 << "Gauss-Seidel, iterations\tJacobi, iterations\tGauss-Seidel, time\tJacobi, time\teps" << std::endl;
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

            out2 << iter_gs << '\t' << iter_jac << '\t' << time_gs << '\t' << time_j << '\t' << eps[i] << std::endl;
        }
    }
    out2.close();

    return 0;
}
