#include "TP05.h"

#include <stack>

void sobrecargaDeTrabalhos(std::istream &in, std::ostream &out) {
    int n, t;
    in >> n >> t;

    std::vector<std::vector<std::pair<int, int>>> graph(n);
    std::vector<int> degree(n, 0);

    for (int k = 0; k < t; ++k) {
        int i, j, d;
        in >> i >> j >> d;

        graph[i - 1].push_back({j - 1, d});
        ++degree[j - 1];
    }

    std::vector<int> es(n, 0);
    std::vector<int> prec(n, -1);
    std::stack<int> s;

    for (int i = 0; i < n; ++i)
        if (degree[i] == 0)
            s.push(i);

    int durMin = -1;
    int vf = -1;

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (durMin < es[v]) {
            durMin = es[v];
            vf = v;
        }

        for (auto [w, d] : graph[v]) {
            if (es[w] < es[v] + d) {
                es[w] = es[v] + d;
                prec[w] = v;
            }

            if ((--degree[w]) == 0)
                s.push(w);
        }
    }

    int maxAmount = 0;
    int maxT = -1;

    for (int t = 0; t < durMin; ++t) {
        int amount = 0;

        for (int v = 0; v < n; ++v)
            for (auto [w, d] : graph[v])
                if (es[v] <= t && es[v] + d > t)
                    ++amount;

        if (amount > maxAmount) {
            maxAmount = amount;
            maxT = t;
        }
    }

    out << durMin << ' ' << maxAmount << ' ' << maxT << '\n';
}

// TESTS

TEST(SobrecargaDeTrabalhos, Exemplo) {
    test(sobrecargaDeTrabalhos,
         "6 9\n"
         "1 3 12\n"
         "1 4 6\n"
         "1 2 3\n"
         "2 5 9\n"
         "2 3 1\n"
         "3 5 5\n"
         "3 6 9\n"
         "5 6 2\n"
         "4 3 6\n",
         "21 4 3\n");
}
