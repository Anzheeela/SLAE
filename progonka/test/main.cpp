#include <src/progonka.h>
#include <iostream>
#include <gtest/gtest.h>

TEST(three_matrix, solve)
{
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {1, 2, 3, 4, 5};
    std::vector<int> c = {2, 3, 4, 5};
    std::vector<int> d = {0, 0, 0, 0, 0};
    three_matrix<int> x;

    x.progonka(a, b, c, d);

    EXPECT_EQ(a.size(), 0u);
};

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {1, 2, 3, 4, 5};
    std::vector<int> c = {2, 3, 4, 5};
    std::vector<int> d = {0, 0, 0, 0, 0};
    three_matrix<int> x;

    std::cout<< x.progonka(a, b, c, d);
};


