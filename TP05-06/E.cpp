#include "TP05.h"

#include <stack>

void cronogramasLda(std::istream &in, std::ostream &out) {
    int n, a, p;
    in >> n >> a;

    std::vector<std::vector<std::pair<int, int>>> graph(n);
    std::vector<int> degree(n, 0);

    for (int k = 0; k < a; ++k) {
        int i, j, d;
        in >> i >> j >> d;

        graph[i - 1].push_back({j - 1, d});
        ++degree[j - 1];
    }

    std::vector<int> es(n, 0);
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
            if (es[w] < es[v] + d)
                es[w] = es[v] + d;

            if ((--degree[w]) == 0)
                s.push(w);
        }
    }

    in >> p;

    for (int k = 0; k < p; ++k) {
        int t, e = 0;
        in >> t;

        for (int v = 0; v < n; ++v)
            for (auto [w, d] : graph[v])
                if (es[v] + d <= t)
                    ++e;

        out << t << ' ' << e << '\n';
    }
}

// TESTS

TEST(CronogramasLda, Exemplo) {
    test(cronogramasLda,
         "6 9\n"
         "1 3 12\n"
         "1 4 6\n"
         "1 2 3\n"
         "2 5 9\n"
         "2 3 1\n"
         "3 5 5\n"
         "3 6 9\n"
         "5 6 2\n"
         "4 3 6\n"
         "10\n"
         "1\n"
         "0\n"
         "12\n"
         "11\n"
         "17\n"
         "21\n"
         "20\n"
         "3\n"
         "5\n"
         "22\n",
         "1 0\n"
         "0 0\n"
         "12 6\n"
         "11 3\n"
         "17 7\n"
         "21 9\n"
         "20 8\n"
         "3 1\n"
         "5 2\n"
         "22 9\n");
}
