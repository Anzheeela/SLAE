#include<three_diag_matrix.h>
// #include <iostream>
#include<gtest/gtest.h>
#include<vector>
#include<type_traits>
// #include<gmock/gmock.h>

TEST(matrix, solve)
{
    std::vector a = {2., 5., 8., 2.};
    std::vector b = {11., 14., 17., 11., 14.};
    std::vector c = {3., 6., 9., 3.};
    three_matrix x = {c, b, a}; 
    std::vector d = {1., 2., 3., 4., 5.};
    std::vector<double> s = progonka(x, d);

    EXPECT_EQ(s.size(), 5);
}

TEST(matrix, solve1)
{
    std::vector a = {0.0475, 0.0523, 0.057};
    std::vector b = {10.8, 9.9, 9., 8.1};
    std::vector c = {0.0321, 0.0369, 0.0416};
    three_matrix x = {c, b, a}; 
    std::vector d = {12.143, 13.0897, 13.6744, 13.8792};
    std::vector<double> s = progonka(x, d);

    EXPECT_NEAR(s[0], 1.12, 0.01);
}
 
TEST(matrix, solve2)
{
    std::vector a = {0.0475, 0.0523, 0.057};
    std::vector b = {10.8, 9.9, 9., 8.1};
    std::vector c = {0.0321, 0.0369, 0.0416};
    three_matrix x = {c, b, a}; 
    std::vector d = {12.143, 13.0897, 13.6744, 13.8792};
    std::vector<double> s = progonka(x, d);

    EXPECT_NEAR(s[1], 1.31, 0.01);
}

TEST(matrix, solve3)
{
    std::vector a = {0.0475, 0.0523, 0.057};
    std::vector b = {10.8, 9.9, 9., 8.1};
    std::vector c = {0.0321, 0.0369, 0.0416};
    three_matrix x = {c, b, a}; 
    std::vector d = {12.143, 13.0897, 13.6744, 13.8792};
    std::vector<double> s = progonka(x, d);

    EXPECT_NEAR(s[2], 1.5, 0.01);
}

TEST(matrix, solve4)
{
    std::vector a = {0.0475, 0.0523, 0.057};
    std::vector b = {10.8, 9.9, 9., 8.1};
    std::vector c = {0.0321, 0.0369, 0.0416};
    three_matrix x = {c, b, a}; 
    std::vector d = {12.143, 13.0897, 13.6744, 13.8792};
    std::vector<double> s = progonka(x, d);

    EXPECT_NEAR(s[3], 1.7, 0.01);
}

TEST(matrix, solve5)
{
    std::vector a = {0.0475, 0.0523, 0.057};
    std::vector b = {10.8, 9.9, 9., 8.1};
    std::vector c = {0.0321, 0.0369, 0.0416};
    three_matrix x = {c, b, a}; 
    std::vector d = {12.143, 13.0897, 13.6744, 13.8792};
    std::vector<double> s = progonka(x, d);

    EXPECT_NEAR(s[3], 1.7, 0.01);
}

TEST(matrix, solve6)
{
    std::vector a = {5., 1.};
    std::vector b = {2., 4., -3.};
    std::vector c = {0., -1., 2.};
    three_matrix x = {c, b, a}; 
    std::vector d = {3., 6., 2.};
    std::vector<double> s = progonka(x, d);

    std::vector<double> r = {1.49, -0.02, -0.68};
    EXPECT_EQ(s, r);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

