// By: Gonçalo Leão

#include <climits>

#include "exercises.h"

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int maxSum = INT_MIN;

    for (unsigned int s{0}; s < n; ++s)
        for (unsigned int e{s}; e < n; ++e) {
            int sum = 0;
            for (unsigned int k{s}; k <= e; k++)
                sum += A[k];

            if (sum > maxSum) {
                maxSum = sum;
                i = s;
                j = e;
            }
        }

    return maxSum;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A, n, i, j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}