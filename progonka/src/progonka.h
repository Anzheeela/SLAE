#pragma once
#include<iostream>
#include<vector>

class three_matrix {
    private:
    std::vector<double> dia_1;
    std::vector<double> dia_2;
    std::vector<double> dia_3;
    std::vector<double> d;

    public:
    std::vector<double> progonka(std::vector<double>& diag_1, std::vector<double>& diag_2, std::vector<double>& diag_3, std::vector<double>& f) {
        auto N = diag_2.size();
        std::vector<double> p;
        std::vector<double> q;
        std::vector<double> x;
        p[1] = -diag_1[0] / diag_2[0];
        q[1] = f[0] / diag_2[0];

        for(int i = 1; i <= N; i++) {
            p[i + 1] = -diag_1[i] / (diag_3[i] * p[i] + diag_2[i]);
            q[i + 1] = (f[i] - diag_3[i] * q[i]) / (diag_3[i] * p[i] + diag_2[i]);   
        }

        for(int n = 0; n <= N-1; n++) {
            x[n] = (f[n] - diag_3[n] * q[n]) / (diag_3[n] * p[n] + diag_2[n]);
        }
        return x;
    }

};

