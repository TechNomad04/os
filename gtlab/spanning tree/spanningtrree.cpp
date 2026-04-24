#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int , int>> edges;
vector<vector<int>> adj;


set<pair<int, int>> treeEdges;

vector<int> parent;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;

    for(int v : adj[u]) {
        if(!visited[v]) {
            parent[v] = u;

            treeEdges.insert({min(u, v), max(u,v) });
            dfs(v);
        }
    }
}

vector<int> getPath(int u, int v) {
    vector<int> pathU, pathV;

    while(u != -1) {
        pathU.push_back(u);
        u = parent[u];
    }

    while(v != -1) {
        pathV.push_back(v);
        v = parent[v];
    }

    reverse(pathU.begin(), pathU.end());
    reverse(pathV.begin(), pathV.end());

    int i = 0;
    while(i < pathU.size() && i < pathV.size() && pathU[i] == pathV[i]) {
        i++;
    }

    vector<int> path;

    for(int j = pathU.size() - 1; j >= i-1; j--) {
        path.push_back(pathU[j]);
    }

    for(int j = i; j < pathV.size(); i++) {
        path.push_back(pathV[j]);
    }

    return path;
}

int main() {
    cin >> n >> m;

    adj.resize(n);
    parent.assign(n, -1);
    visited.assign(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    cout << "Spanning Tree Edges:\n";
    for (auto e : treeEdges) {
        cout << e.first << " - " << e.second << "\n";
    }

    cout << "\nNon-Tree Edges:\n";
    vector<pair<int,int>> nonTree;

    for(auto e : edges) {
        pair<int, int> edge = {min(e.first, e.second), max(e.first, e.second)};

        if(treeEdges.find(edge) == treeEdges.end()) {
            nonTree.push_back(e);
            cout << e.first << "-" << e.second << "\n";
        }
    }

    cout << "\nFundamental Circuits:\n";
    for(auto e: nonTree) {
        int u = e.first;
        int v = e.second;

        vector<int> path = getPath(u, v);
        for (int x : path) {
            cout << x << " ";
        }
        cout << u; // to complete cycle

        cout << "\n";
    }
}