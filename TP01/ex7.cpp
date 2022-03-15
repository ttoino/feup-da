// By: Gonçalo Leão

#include "exercises.h"

#include <algorithm>
#include <vector>

double minimumAverageCompletionTime(std::vector<unsigned int> tasks,
                                    std::vector<unsigned int> &orderedTasks) {
    orderedTasks = tasks;

    std::sort(orderedTasks.begin(), orderedTasks.end());

    unsigned int currentTime{0};
    unsigned int acc{0};

    for (unsigned int t : orderedTasks) {
        currentTime += t;
        acc += currentTime;
    }

    return (double)acc / orderedTasks.size();
}

/// TESTS ///
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(TP1_Ex7, taskOrdering) {
    std::vector<unsigned int> tasks = {15, 8, 3, 10};
    std::vector<unsigned int> orderedTasks;
    double averageTime = minimumAverageCompletionTime(tasks, orderedTasks);
    EXPECT_EQ(orderedTasks.size(), 4);
    ASSERT_NEAR(averageTime, 17.75, 0.00001);
    ASSERT_THAT(orderedTasks, ::testing::ElementsAre(3, 8, 10, 15));
}