#include <iostream>
#include <vector>

using namespace std;

bool is_safe(int v, vector<vector<int>> &graph, vector<int> &path, int pos ) {
    if(graph[path[pos-1]][v] == 0)
    return false;

    for(int i = 0; i < pos; i++) {
        if(path[i] == v)
        return false;
    }

    return true;
}

bool hamcycleutil(vector<vector<int>> &graph, vector<int> &path, int pos, int n) {
    if(pos == n) 
    return graph[path[pos-1]][path[0]] == 1;

    for(int v = 1; v < n; v++) {
        if(is_safe(v, graph, path, pos)) {
            path[pos] = v;

            if(hamcycleutil(graph, path, pos+1, n))
            return true;

            path[pos] = -1;
        }
    }

    return false;
}

void hamcycle(vector<vector<int>> &graph, int n) {
    vector<int> path(n, -1);
    path[0] = 0;
    if(!hamcycleutil(graph, path, 1, n)) {
        cout << "No hamiltonian cycle" << endl;
        return;
    }

    cout << "Hamiltonian cycle: " << endl;
    for(int i = 0; i < n; i++)
    cout << path[i] << " ";
    cout << path[0] << endl;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
        cin >> graph[i][j];
    }

    hamcycle(graph, n);

    return 0;
} 