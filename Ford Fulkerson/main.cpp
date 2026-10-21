
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Edge {
    int u, v, c;
};

int n;
vector<vector<int>> res;
vector<bool> visited;
vector<int> parent;
bool DFS(int u, int t) {
    visited[u] = true;
    if (u == t)
        return true;
    for (int v = 0; v < n; v++) {
        if (res[u][v] > 0 && !visited[v]) {
            parent[v] = u;

            if (DFS(v, t))
                return true;
        }
    }
    return false;
}

int FordFulkerson(int s, int t) {
    int maxFlow = 0;
    while (true) {
        visited.assign(n, false);
        parent.assign(n, -1);
        if (!DFS(s, t))
            break;
        int flow = 1000000000;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];

            if (res[u][v] < flow)
                flow = res[u][v];
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];

            res[u][v] -= flow;
            res[v][u] += flow;
        }
        maxFlow += flow;
    }
    return maxFlow;
}

int runTest(int vertices, vector<Edge> edges, int s, int t) {
    n = vertices;
    res.assign(n, vector<int>(n, 0));

    for (Edge e : edges)
        res[e.u][e.v] += e.c;

    return FordFulkerson(s, t);
}

int main() {
    cout << "FF Killer: "
         << runTest(6, {
             {0, 1, 1},
             {0, 2, 1},
             {1, 3, 1},
             {1, 4, 1},
             {2, 3, 1},
             {3, 5, 1},
             {4, 5, 1}
         }, 0, 5) << endl;

    cout << "CP4 style: "
         << runTest(6, {
             {0, 1, 16},
             {0, 2, 13},
             {1, 2, 10},
             {2, 1, 4},
             {1, 3, 12},
             {3, 2, 9},
             {2, 4, 14},
             {4, 3, 7},
             {3, 5, 20},
             {4, 5, 4}
         }, 0, 5) << endl;

    cout << "CS4234 MF Demo: "
         << runTest(6, {
             {0, 1, 10},
             {0, 2, 10},
             {1, 2, 2},
             {1, 3, 4},
             {1, 4, 8},
             {2, 4, 9},
             {4, 3, 6},
             {3, 5, 10},
             {4, 5, 10}
         }, 0, 5) << endl;

    cout << "Matching with Capacity: "
         << runTest(6, {
             {0, 1, 2},
             {0, 2, 1},
             {1, 3, 1},
             {1, 4, 1},
             {2, 3, 1},
             {2, 4, 1},
             {3, 5, 1},
             {4, 5, 2}
         }, 0, 5) << endl;

    return 0;
}

