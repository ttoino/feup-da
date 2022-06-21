#include "TP05.h"

int countDFS(int node, bool (&matrix)[26][26], bool (&visited)[26]) {
    int count = 0;

    for (int i = 0; i < 26; ++i)
        if (matrix[i][node] && !visited[i]) {
            count += 1 + countDFS(i, matrix, visited);
            visited[i] = true;
        }

    return count;
}

void quantasDepois(std::istream &in, std::ostream &out) {
    bool matrix[26][26] = {false};

    std::string word, other;
    std::getline(in, other);

    while (true) {

        std::getline(in, word);
        if (word == "#")
            break;

        for (int i = 0; i < word.size() && i < other.size(); ++i) {
            char c1 = word[i], c2 = other[i];

            if (word[i] == other[i])
                continue;

            matrix[c1 - 'A'][c2 - 'A'] = 1;
            break;
        }

        other = word;
    }

    std::getline(in, word);
    char wanted = word[0];
    bool visited[26] = {false};

    out << countDFS(wanted - 'A', matrix, visited) << '\n';
}

// TESTS

#include <gtest/gtest.h>

TEST(QuantasDepois, Exemplo1) {
    test(quantasDepois,
         "MPMAAC\n"
         "MPAMJ\n"
         "MMCAA\n"
         "MMJA\n"
         "CAAP\n"
         "CAAJP\n"
         "#\n"
         "P\n",
         "4\n");
}

TEST(QuantasDepois, Exemplo2) {
    test(quantasDepois,
         "MPMAAC\n"
         "MPAMJ\n"
         "MMCAA\n"
         "MMJA\n"
         "CAAP\n"
         "CAAJP\n"
         "#\n"
         "M\n",
         "3\n");
}

TEST(QuantasDepois, Exemplo3) {
    test(quantasDepois,
         "MPMAAC\n"
         "MPAMJ\n"
         "MMCAA\n"
         "MMJA\n"
         "CAAP\n"
         "CAAJP\n"
         "#\n"
         "A\n",
         "0\n");
}

TEST(QuantasDepois, Exemplo4) {
    test(quantasDepois,
         "B\n"
         "MP\n"
         "MPAB\n"
         "MPAC\n"
         "MMCAR\n"
         "CA\n"
         "KR\n"
         "#\n"
         "P\n",
         "3\n");
}
