#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int v, u, weight;
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DSU {
    public:
        vector<int> parent;
        vector<int>rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            for(int i = 0; i < n; i++) 
            parent[i] = i;
        }

        int find(int n) {
            if(parent[n] != n) 
            parent[n] = find(parent[n]);
            return parent[n]; 
        }

        void unite(int x, int y) {
            int px = find(x);
            int py = find(y);

            if(px == py)
            return;

            if(rank[px] < rank[py])
            parent[px] = py;
            else if(rank[px] > rank[py])
            parent[py] = px;
            else {
                parent[py] = px;
                rank[px]++;
            }
        } 
};

int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);

    for(int i = 0; i < E; i++)
    cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    DSU dsu(V);
    int count = 0, mst_weight = 0;

    sort(edges.begin(), edges.end(), cmp);

    vector<pair<int, int>> final;

    for(auto edge: edges) {
        if(dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst_weight += edge.weight;
            final.push_back({edge.u, edge.v});
            count ++;
            if(count == V-1)
            break;
        }
    }

    cout << "--------------" << endl;

    for(int i = 0; i < final.size(); i++) 
    cout << final[i].first << " " << final[i].second << endl;

    return 0;
}