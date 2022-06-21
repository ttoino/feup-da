#include "TP05.h"

#include <set>
#include <stack>

using Graph = std::vector<std::vector<int>>;

void dfs(Graph &graph, std::stack<int> &s, std::set<int> &visited, int node) {
    if (!visited.contains(node)) {
        visited.insert(node);

        for (int other : graph.at(node)) {
            dfs(graph, s, visited, other);
        }

        s.push(node);
    }
}

void sociologia(std::istream &in, std::ostream &out) {
    int n, m;
    in >> n;

    for (int i = 0; i < n; ++i) {
        out << "Caso #" << i + 1 << '\n';

        in >> m;

        Graph graph(m + 1);
        Graph transposed(m + 1);

        std::stack<int> s{};
        std::set<int> visited{};

        for (int j = 0; j < m; ++j) {
            int a, g, o;
            in >> a >> g;

            for (int k = 0; k < g; ++k) {
                in >> o;
                graph[a].push_back(o);
                transposed[o].push_back(a);
            }
        }

        for (int j = 1; j <= m; ++j) {
            dfs(graph, s, visited, j);
        }

        visited.clear();

        int groups = 0;
        int outside = 0;

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            std::stack<int> ss{};
            dfs(transposed, ss, visited, node);

            int n = ss.size();

            if (n >= 4)
                ++groups;
            else
                outside += n;
        }

        out << groups << ' ' << outside << '\n';
    }
}

// TESTS

TEST(Sociologia, Exemplo) {
    test(sociologia,
         "4\n"
         "4\n"
         "1 3 2 4 3\n"
         "4 0\n"
         "2 2 1 3\n"
         "3 2 2 1\n"
         "6\n"
         "1 2 3 5\n"
         "2 2 3 4\n"
         "4 1 2\n"
         "3 2 2 1\n"
         "6 1 5\n"
         "5 2 6 1\n"
         "8\n"
         "1 4 6 2 4 5\n"
         "3 1 2\n"
         "2 2 3 4\n"
         "4 1 5\n"
         "6 0\n"
         "5 3 4 8 7\n"
         "7 1 5\n"
         "8 2 5 3\n"
         "10\n"
         "1 4 6 2 4 5\n"
         "3 2 2 1\n"
         "9 0\n"
         "2 2 3 4\n"
         "4 2 5 9\n"
         "6 1 1\n"
         "5 3 4 8 7\n"
         "7 1 5\n"
         "8 1 5\n"
         "10 1 9\n",
         "Caso #1\n"
         "0 4\n"
         "Caso #2\n"
         "1 0\n"
         "Caso #3\n"
         "1 2\n"
         "Caso #4\n"
         "2 2\n");
}
