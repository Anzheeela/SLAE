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