#include "exercises.h"

Labyrinth::Labyrinth(int values[10][10]) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            labyrinth[i][j] = values[i][j];
}

#include <iostream>

void Labyrinth::print() const {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << labyrinth[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Labyrinth::findGoal(int x, int y) {
    initializeVisited();
    return findGoalRecursive(x, y);
}

bool Labyrinth::findGoalRecursive(int x, int y) {
    std::cout << x << '\t' << y << std::endl;

    if (x < 0 || y < 0 || x >= 10 || y >= 10 || visited[x][y] ||
        labyrinth[x][y] == 0)
        return false;
    if (labyrinth[x][y] == 2)
        return true;

    visited[x][y] = true;

    if (findGoalRecursive(x + 1, y))
        return true;
    if (findGoalRecursive(x - 1, y))
        return true;
    if (findGoalRecursive(x, y + 1))
        return true;
    if (findGoalRecursive(x, y - 1))
        return true;

    return false;
}

void Labyrinth::initializeVisited() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            visited[i][j] = false;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP2_Ex1, testLabyrinthPossible) {
    // This test assumes that the mazes only have a possible path to the exit
    int lab1[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 1, 0, 1, 0, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 0, 1, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 0, 1, 2, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    Labyrinth l1(lab1);
    EXPECT_EQ(l1.findGoal(1, 1), true);
}

TEST(TP2_Ex1, testLabyrinthImpossible) {
    int lab1[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 1, 0, 1, 0, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 0, 1, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 2, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    Labyrinth l1(lab1);
    EXPECT_EQ(l1.findGoal(1, 1), false);
}