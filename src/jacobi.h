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