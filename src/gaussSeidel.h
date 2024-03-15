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