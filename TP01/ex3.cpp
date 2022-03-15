// By: Gonçalo Leão

#include <climits>
#include <memory>

#include "exercises.h"

bool isCorrect(unsigned int C[], unsigned int usedCoins[], unsigned int n,
               unsigned int T) {
    unsigned int totalValue = 0;
    for (int i = 0; i < n; i++)
        totalValue += C[i] * usedCoins[i];

    return totalValue == T;
}

bool changeMakingBF(unsigned int C[], unsigned int Stock[], unsigned int n,
                    unsigned int T, unsigned int usedCoins[]) {
    unsigned int numCoins = UINT_MAX;
    auto mod = std::make_unique<unsigned int[]>(n);
    auto coins = std::make_unique<unsigned int[]>(n);
    unsigned int stockProduct = 1;
    unsigned int stockSum = 0;

    for (int i = 0; i < n; i++) {
        coins[i] = Stock[i];
        stockSum += Stock[i];
        mod[i] = stockProduct;
        stockProduct *= (Stock[i] + 1);
    }

    for (int j = 1; j <= stockProduct; j++) {
        if (isCorrect(C, coins.get(), n, T) && stockSum < numCoins) {
            numCoins = stockSum;
            for (int i = 0; i < n; i++) {
                usedCoins[i] = coins[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (j % mod[i] == 0) {
                if (coins[i] != 0) {
                    coins[i]--;
                    stockSum--;
                } else {
                    coins[i] = Stock[i];
                    stockSum += Stock[i];
                }
            }
        }
    }

    return numCoins != UINT_MAX;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex3, hasBFChangeCanonical) {
    unsigned int C[] = {1, 2, 5, 10};
    unsigned int Stock[] = {1, 1, 1, 1};
    unsigned int n = 4;
    unsigned int usedCoins[] = {0, 0, 0, 0};

    EXPECT_EQ(changeMakingBF(C, Stock, n, 13, usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    unsigned int Stock2[] = {1, 2, 4, 2};
    EXPECT_EQ(changeMakingBF(C, Stock2, n, 38, usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 3);
    EXPECT_EQ(usedCoins[3], 2);
}

TEST(TP1_Ex3, hasBFChangeNonCanonical) {
    unsigned int C[] = {1, 4, 5};
    unsigned int Stock[] = {2, 2, 1};
    unsigned int n = 3;
    unsigned int usedCoins[] = {0, 0, 0};

    EXPECT_EQ(changeMakingBF(C, Stock, n, 6, usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    EXPECT_EQ(changeMakingBF(C, Stock, n, 8, usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);
}

TEST(TP1_Ex3, hasNoBFChange) {
    unsigned int C[] = {1, 2, 5, 10};
    unsigned int Stock[] = {0, 1, 1, 1};
    unsigned int n = 4;
    unsigned int usedCoins[] = {0, 0, 0, 0};

    EXPECT_EQ(changeMakingBF(C, Stock, n, 18, usedCoins), false);
    EXPECT_EQ(changeMakingBF(C, Stock, n, 1, usedCoins), false);
}