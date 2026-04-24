#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    for(int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<bool> visited(V, false);

    pq.push({0, 0});

    int mst_weight = 0;

    while(!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if(visited[node])
        continue;

        visited[node] = true;
        mst_weight += wt;
        for(auto it: adj[node]) {
            int neighbour = it.first;
            int weight = it.second;

            if(!visited[neighbour]) {
                pq.push({weight, neighbour});
            }
        }
    }

    cout << mst_weight<< endl;

}