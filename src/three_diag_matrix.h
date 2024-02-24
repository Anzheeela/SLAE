#include<iostream>
#include<vector>
#include<fstream>

struct three_matrix {
    std::vector<double> diag_1; // c
    std::vector<double> diag_2; // b
    std::vector<double> diag_3; // a
};

std::vector<double> progonka(const three_matrix &mat, const std::vector<double> &f) {
    unsigned int N = (unsigned int)(mat.diag_2.size());
    std::vector<double> p = std::vector<double>(N);
    std::vector<double> q = std::vector<double>(N);
    std::vector<double> x = std::vector<double>(N);
    p[1] = -mat.diag_1[0] / mat.diag_2[0];
    q[1] = f[0] / mat.diag_2[0];

    for(unsigned int i = 1; i <= N - 2; i++) {
        p[i + 1] = -mat.diag_1[i] / 
                    (mat.diag_3[i - 1] * p[i] + mat.diag_2[i]);
        q[i + 1] = (f[i] - mat.diag_3[i - 1] * q[i]) / 
                    (mat.diag_3[i - 1] * p[i] + mat.diag_2[i]);   
    }
    
    x[N - 1] = (f[N - 1] - mat.diag_3[N - 2] * q[N - 1]) / 
                (mat.diag_3[N - 2] * p[N - 1] + mat.diag_2[N - 1]);

    for(unsigned int n = N - 1; n > 0; n--) {
        x[n - 1] = p[n] * x[n] + q[n];
    }
    return x;
}
