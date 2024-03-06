#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

struct sol
{
    int num_iter;
    std::vector<double> solution;
};


sol gaussSeidel(std::vector<std::vector<double>> A, std::vector<double> b, std::vector<double> x0, double tol, int max_iter=1000) {
    int n = A.size();
    std::vector<double> x = x0;
    int it;
    for (int iter = 0; iter < max_iter; ++iter) {
        std::vector<double> x_new = x;
        for (int i = 0; i < n; ++i) {
            double s1 = 0.0;
            for (int j = 0; j < i; ++j) {
                s1 += A[i][j] * x_new[j];
            }
            double s2 = 0.0;
            for (int j = i + 1; j < n; ++j) {
                s2 += A[i][j] * x[j];
            }
            x[i] = (b[i] - s1 - s2) / A[i][i];
        }
        bool converged = true;
        for (int i = 0; i < n; ++i) {
            if (abs(x[i] - x_new[i]) >= tol) {
                converged = false;
                break;
            }
        }
        if (converged) {
            break;
        }
        it = iter;
    }
    sol sol_;
    sol_.num_iter = it;
    sol_.solution = x;
    return sol_;
}


sol jacobi(std::vector<std::vector<double>> A, std::vector<double> b, std::vector<double> x0, double tol, int max_iter=1000) {
    int n = A.size();
    std::vector<double> x = x0, x_new(n);
    int it;
    for (int iter = 0; iter < max_iter; ++iter) {
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }
        bool converged = true;
        for (int i = 0; i < n; ++i) {
            if (abs(x[i] - x_new[i]) >= tol) {
                converged = false;
                break;
            }
        }
        if (converged) {
            break;
        }
        x = x_new;
        it = iter;
    }
    sol sol_;
    sol_.num_iter = it;
    sol_.solution = x;
    return sol_;
}

std::vector<double> progonka(const std::vector<std::vector<double>>& A, const std::vector<double>& b) {
    int n = b.size();
    std::vector<double> x(n);
    std::vector<double> c(n);
    std::vector<double> d(n);

    c[0] = A[0][1] / A[0][0];
    d[0] = b[0] / A[0][0];
    for (int i = 1; i < n; ++i) {
        double m = 1.0 / (A[i][i] - A[i][i - 1] * c[i - 1]);
        c[i] = A[i][i + 1] * m;
        d[i] = (b[i] - A[i][i - 1] * d[i - 1]) * m;
    }

    x[n - 1] = d[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        x[i] = d[i] - c[i] * x[i + 1];
    }

    return x;
}

std::vector<double> linspace(double start, double end, int num) {
    std::vector<double> result;
    double step = (end - start) / (num - 1);
    
    for (int i = 0; i < num; ++i) {
        result.push_back(start + i * step);
    }
    
    return result;
}
