#include "TP05.h"

#include <algorithm>
#include <stack>

// TODO
void sobPressao(std::istream &in, std::ostream &out) {
    int n, p;
    in >> n;

    std::vector<std::vector<int>> preferences(n);

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            int t;
            in >> t;

            preferences[k].push_back(t - 1);
        }
    }

    in >> p;

    for (int j = 0; j < p; ++j) {
        std::vector<std::vector<int>> graph(n);
        std::vector<int> degree(n, 0);

        for (int k = 0; k < n; ++k) {
            int s;
            in >> s;

            for (int i : preferences[k]) {
                if (i == s - 1)
                    break;

                graph[s - 1].push_back(i);
                ++degree[i];
            }
        }

        std::vector<int> es(n, 0);
        std::stack<int> s;

        for (int i = 0; i < n; ++i)
            if (degree[i] == 0)
                s.push(i);

        int max = -1;

        while (!s.empty()) {
            int v = s.top();
            s.pop();

            if (max < es[v])
                max = es[v];

            for (int w : graph[v]) {
                if (es[w] < es[v] + 1)
                    es[w] = es[v] + 1;

                if ((--degree[w]) == 0)
                    s.push(w);
            }
        }

        if (std::all_of(degree.begin(), degree.end(),
                        [](int i) { return i == 0; }))
            out << max << '\n';
        else
            out << "Indeterminado (nao Pareto-optima)\n";
    }
}

// TESTS

TEST(SobPressao, Exemplo) {
    test(sobPressao,
         "7\n"
         "1 2 3 6 7 5 4\n"
         "1 2 3 5 6 7 4\n"
         "4 1 2 3 5 7 6\n"
         "3 1 2 5 7 6 4\n"
         "1 2 3 6 4 5 7\n"
         "1 2 3 6 7 4 5\n"
         "2 1 3 4 5 6 7\n"
         "6\n"
         "1 5 4 3 2 6 7\n"
         "2 3 7 1 6 5 4\n"
         "1 5 4 3 6 7 2\n"
         "1 5 4 3 2 7 6\n"
         "2 3 5 7 4 1 6\n"
         "6 1 4 3 5 7 2\n",
         "3\n"
         "Indeterminado (nao Pareto-optima)\n"
         "2\n"
         "4\n"
         "Indeterminado (nao Pareto-optima)\n"
         "2\n");
}
