#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void bellmanford(int src, vector<vector<int>> cost, int n) {
    vector<int> dist(n, INF);
    int k, u, v;
    dist[src] = 0;
    for(k = 0; k < n-1; k++) {
        for(u = 0; u < n; u++) {
            for(v = 0; v < n; v++) {
                if(cost[u][v] != INF && dist[u] != INF) 
                dist[v] = min(dist[v], dist[u]+cost[u][v]);
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

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost matrix (999 for INF):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 999) cost[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        bellmanford(i, cost, n);
    }
}