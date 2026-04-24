#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
        cin >> dist[i][j];
    }

    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n));
    vector<vector<int>> parent(N, vector<int>(n));

    for(int mask = 1; mask < N; mask++) {
        for(int u = 0; u < n; u++) {
            if(!(mask & (1 << u))) continue;

            for(int v = 0; v < n; v++) {
                if(!(mask & (1 << v))) continue;

                int newMask = mask | (1 << v);
                if(dp[newMask][v] > dp[mask][u] + dist[u][v]) {
                    dp[newMask][v] = dp[mask][u] + dist[u][v];
                    parent[newMask][v] = u;
                }
            }
        }
    }

    int lastMask = N-1;
    int minCost = INF, lastCity = -1;

    for(int i = 1; i < n; i++) {
        int cost = dp[lastMask][i] + dist[i][0];
        if(cost < minCost) {
            minCost = cost;
            lastCity = i;
        }
    }

    vector <int> path;
    int mask = lastMask;
    int curr = lastCity;

    while(curr != -1) {
        path.push_back(curr);

        int temp = parent[mask][curr];
        mask = mask ^ (1 << curr);
        curr = temp;
    }

    reverse(path.begin(), path.end());
    path.push_back(0);

    cout << "Path: ";
    for(int city : path) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}