#include <src/progonka.h>
// #include <iostream>
#include <gtest/gtest.h>
#include <vector>

TEST(three_matrix, solve)
{
    std::vector a = {1., 2., 3., 4.};
    std::vector b = {1., 2., 3., 4., 5.};
    std::vector c = {2., 3., 4., 5.};
    std::vector d = {0., 0., 0., 0., 0.};
    three_matrix x;

    x.progonka();

    EXPECT_EQ(a.size(), 0u);
};

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


