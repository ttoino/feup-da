#include <memory>

#include "exercises.h"

unsigned long s_recursive(unsigned int n, unsigned int k) {
    if (k == 1 || k == n)
        return 1;

    return s_recursive(n - 1, k - 1) + k * s_recursive(n - 1, k);
}

unsigned long _b_recursive(unsigned int n, unsigned int k) {
    if (k > n)
        return 0;

    return s_recursive(n, k) + _b_recursive(n, k + 1);
}

unsigned long b_recursive(unsigned int n) { return _b_recursive(n, 1); }

unsigned long s_dynamic(unsigned int n, unsigned int k) {
    int maxj = n - k;
    auto c = std::make_unique<unsigned long[]>(maxj + 1);

    for (int j = 0; j <= maxj; ++j)
        c[j] = 1;

    for (int i = 2; i <= k; ++i)
        for (int j = 1; j <= maxj; ++j)
            c[j] += i * c[j - 1];

    return c[maxj];
}

unsigned long b_dynamic(unsigned int n) {
    unsigned long r = 0;
    for (int i = 1; i <= n; ++i)
        r += s_dynamic(n, i);

    return r;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex5, testPartitioningRecursive) {
    EXPECT_EQ(1, s_recursive(3, 3));
    EXPECT_EQ(3025, s_recursive(9, 3));
    EXPECT_EQ(22827, s_recursive(10, 6));

    EXPECT_EQ(5, b_recursive(3));
    EXPECT_EQ(203, b_recursive(6));
    EXPECT_EQ(1382958545, b_recursive(15));
}

TEST(TP4_Ex5, testPartitioningDynamic) {
    EXPECT_EQ(1, s_dynamic(3, 3));
    EXPECT_EQ(3025, s_dynamic(9, 3));
    EXPECT_EQ(22827, s_dynamic(10, 6));

    EXPECT_EQ(5, b_dynamic(3));
    EXPECT_EQ(203, b_dynamic(6));
    EXPECT_EQ(1382958545, b_dynamic(15));
}