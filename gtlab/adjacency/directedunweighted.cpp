#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v) {
    graph[u].push_back(v);
}

void display(vector<vector<int>> &graph, int n) {
    int i;
    for(i = 0; i < n; i++) {
        for(int j = 0; j < graph[i].size(); j++)
        cout << i << "->" << graph[i][j] << endl;
    }
}

int main() {
    int v;
    cin >> v;

    vector<vector<int>> graph(v);
    for(int i = 0; i < v; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    display(graph, v);
}