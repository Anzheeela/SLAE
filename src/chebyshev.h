sol chebyshev(std::vector<std::vector<double>> A, std::vector<double> b, double tol, int maxIter=1000) {
    int n = A.size();
    std::vector<double> x(n, 0.0), x_;
    double it;
    std::vector<double> xPrev = x;
    double omega = 1.0 / (1.0 + sqrt(1.0 - pow(cos(M_PI/n), 2)));

    sol cheb;
    cheb.solution = x;
    cheb.num_iter = 0;

    std::vector<double> error;
    error.push_back(0.0);
    error.push_back(0.0);
    
    for (int iter = 0; iter < maxIter; iter++) {
        xPrev = x;
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (1.0 - omega) * xPrev[i] + omega * ((b[i] - sum) / A[i][i]);
        }
        
        bool converged = true;
        for (int i = 0; i < n; ++i) {
            if (abs(x[i] - xPrev[i]) >= tol) {
                converged = false;
                break;
            }
        }
        if (converged) {
                break;
        }
        x_ = x;
        it = iter;
    }
    cheb.num_iter = it;
    cheb.solution = x_;
    return cheb;
}