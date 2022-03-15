// By: Gonçalo Leão

#include "exercises.h"

// O(T³)
bool sum3_a(unsigned int T, unsigned int nums[3]) {
    if (T < 3)
        return false;

    for (unsigned a{1}; a <= T - 2; a++)
        for (unsigned b{1}; b <= T - 2; b++)
            for (unsigned c{1}; c <= T - 2; c++)
                if (a + b + c == T) {
                    nums[0] = a;
                    nums[1] = b;
                    nums[2] = c;
                    return true;
                }

    return false;
}

// O(1)
bool sum3_b(unsigned int T, unsigned int nums[3]) {
    if (T < 3)
        return false;

    nums[0] = 1;
    nums[1] = 1;
    nums[2] = T - 2;
    return true;

    // return false;
}

/// TESTS ///
#include <gtest/gtest.h>

void compareSums(unsigned int selected[3], unsigned int expectedSum) {
    EXPECT_EQ(selected[0] + selected[1] + selected[2], expectedSum);
}

TEST(TP1_Ex1, 3sumAExists) {
    unsigned int selected[3];

    unsigned int T = 10;
    EXPECT_EQ(sum3_a(T, selected), true);
    compareSums(selected, T);

    T = 18;
    EXPECT_EQ(sum3_a(T, selected), true);
    compareSums(selected, T);
}

TEST(TP1_Ex1, 3sumANotExists) {
    unsigned int selected[3];

    unsigned int T = 1;
    EXPECT_EQ(sum3_a(T, selected), false);
}

TEST(TP1_Ex1, 3sumBExists) {
    unsigned int selected[3];

    unsigned int T = 10;
    EXPECT_EQ(sum3_b(T, selected), true);
    compareSums(selected, T);

    T = 18;
    EXPECT_EQ(sum3_b(T, selected), true);
    compareSums(selected, T);
}

TEST(TP1_Ex1, 3sumBNotExists) {
    unsigned int selected[3];

    unsigned int T = 1;
    EXPECT_EQ(sum3_b(T, selected), false);
}