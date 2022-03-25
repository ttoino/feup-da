#include <cstdint>
#include <memory>
#include <sstream>

#include "exercises.h"

std::string calcSum(int sequence[], unsigned long n) {
    auto s = std::make_unique<int[]>(n);
    std::stringstream st{};

    for (int m = 0; m < n; ++m) {
        int mins = INT_MAX;
        int mini = INT_MAX;

        for (int i = 0; i < n - m; ++i) {
            s[i] += sequence[i + m];

            if (s[i] < mins) {
                mins = s[i];
                mini = i;
            }
        }

        st << mins << ',' << mini << ';';
    }

    return st.str();
}

void testPerformanceCalcSum() {
    // TODO
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex4, CalcSumArrayTest) {
    int sequence[5] = {4, 7, 2, 8, 1};
    int sequence2[9] = {6, 1, 10, 3, 2, 6, 7, 2, 4};

    EXPECT_EQ("1,4;9,1;11,2;18,1;22,0;", calcSum(sequence, 5));
    EXPECT_EQ("1,1;5,3;11,3;16,1;20,3;24,3;31,1;35,1;41,0;",
              calcSum(sequence2, 9));

    testPerformanceCalcSum();
}