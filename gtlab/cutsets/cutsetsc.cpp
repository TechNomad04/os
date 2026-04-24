#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> edges;

void dfs(int node, vector<vector<int>> &adj, vector<bool> & vis) {
    vis[node] = true;
    for(int nei: adj[node]) {
        if(!vis[node])
        dfs(nei, adj, vis);
    }
}

bool isConnected(vector<vector<int>> &adj) {
    vector<bool> vis(n, false);
    dfs(0, adj, vis);

    for(int i = 0; i < n; i++) {
        if(!vis[i]) return false;

        return true;
    }
}

bool isCutset(int mask) {
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        if(!(mask & (1 << i))) {
            int u = edges[i].first;
            int v = edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    return isConnected(adj);
}

int main() {
    cin >> n >> m;
    edges.resize(m);
    for(int i = 0; i < m; i++) 
    cin >> edges[i].first >> edges[i].second;

    int total = 1 << m;
    vector<int> cutsets;

    for(int mask = 1; mask < total; mask++) {
        if (isCutset(mask))
        cutsets.push_back(mask);
    }

    cout << "All cutsets:\n";
    for(int mask : cutsets) {
        cout << "{ ";
        for(int i = 0; i < m; i++) {
            if(mask & (1 << i)) 
            cout << "(" << edges[i].first << "," << edges[i].second << ")";
        }

        cout << "}\n";
    }

    cout << "\nMinimal Cutset\n";

    for(int i = 0; i < cutsets.size(); i++) {
        bool minimal = true;

        for(int j = 0; j < cutsets.size(); j++) {
            if(i == j) continue;

            if((cutsets[j] & cutsets[i]) == cutsets[j]) {
                if(cutsets[i] != cutsets[j]) {
                    minimal = false;
                    break;
                }
            }
        }

        if(minimal) {
            int mask = cutsets[i];
            cout << "{ ";
            for(int k = 0; k < m; k++) {
                if(mask & (1 << k)) {
                    cout << "(" << edges[k].first << "," << edges[k].second << ") ";
                }
            }
            cout << "}\n";
        }
    }
}