#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++) 
            parent[i] = i;
        }

        int find(int x) {
            if(parent[x] != x)
            parent[x] = find(parent[x]);
            return parent[x];
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
                rank[px] ++;
            }
        }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight): \n";
    for(int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(V);
    int mst_weight = 0, count = 0;

    for(auto edge: edges) {
        if(dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            cout << edge.u << "-" << edge.v << ":" << edge.weight << endl;
            mst_weight += edge.weight;

            count++;
            if(count == V - 1) break;

        }
    }

    cout << "\nTotal weight of MST: " << mst_weight << endl;

    return 0;
}