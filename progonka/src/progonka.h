#include<iostream>
#include<vector>
#include<fstream>

struct three_matrix {
    std::vector<double> diag_1;
    std::vector<double> diag_2;
    std::vector<double> diag_3;
};

std::vector<double> progonka(three_matrix x, std::vector<double> f);