// By: Gonçalo Leão

#include "exercises.h"

unsigned int sumArray(unsigned int a[], unsigned int n) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>

bool isCanonical(unsigned int C[], unsigned int n) {
    if (n < 3)
        return true;

    auto Stock = std::make_unique<unsigned int[]>(n),
         usedCoinsBF = std::make_unique<unsigned int[]>(n),
         usedCoinsGreedy = std::make_unique<unsigned int[]>(n);

    std::fill(Stock.get(), Stock.get() + n, C[n - 1]);
    std::fill(usedCoinsBF.get(), usedCoinsBF.get() + n, 0);
    std::fill(usedCoinsGreedy.get(), usedCoinsGreedy.get() + n, 0);

    for (unsigned int x{C[2] + 1}; x < C[n - 2] + C[n - 1]; ++x) {
        changeMakingBF(C, Stock.get(), n, x, usedCoinsBF.get());
        changeMakingGreedy(C, Stock.get(), n, x, usedCoinsGreedy.get());

        for (unsigned int i{0}; i < n; ++i)
            if (usedCoinsBF[i] != usedCoinsGreedy[i])
                return false;
    }

    return true;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex5, canonicalTrue) {
    unsigned int C[] = {1, 2, 5};
    EXPECT_EQ(isCanonical(C, 3), true);

    unsigned int C2[] = {1, 2, 5, 10};
    EXPECT_EQ(isCanonical(C2, 4), true);
}

TEST(TP1_Ex5, canonicalFalse) {
    unsigned int C[] = {1, 4, 5};
    EXPECT_EQ(isCanonical(C, 3), false);
}