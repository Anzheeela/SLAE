#include<iostream>
#include<vector>
#include<fstream>

struct three_matrix {
    std::vector<double> diag_1; // c
    std::vector<double> diag_2; // b
    std::vector<double> diag_3; // a
};

std::vector<double> progonka(three_matrix x, std::vector<double> f);