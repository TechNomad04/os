#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void dijkstra(int src, vector<vector<int>>& graph, int n) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;

        // find minimum distance node
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Router " << src << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << i << " -> INF\n";
        else cout << i << " -> " << dist[i] << "\n";
    }
    cout << "-----------------\n";
}

int main() {
    int n;
    cout << "Enter number of routers: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix (999 for INF):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 999) graph[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        dijkstra(i, graph, n);
    }
}