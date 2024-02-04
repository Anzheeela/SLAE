#include <progonka.h>
// #include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <type_traits>

TEST(matrix, solve)
{
    std::vector a = {2., 5., 8., 2.};
    std::vector b = {11., 14., 17., 11., 14.};
    std::vector c = {3., 6., 9., 3.};
    three_matrix x = {c, b, a}; 
    std::vector d = {1., 2., 3., 4., 5.};
    std::vector<double> s = progonka(x, d);

    EXPECT_EQ(s.size(), 5);
};

 
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


