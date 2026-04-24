#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int pos, int n) {
    if(graph[path[pos-1]][v] == 0)
    return false;

    for(int i = 0; i < pos; i++) {
        if(path[i] == v)
        return false;
    }

    return true;
}

bool hamCycleUtil(vector<vector<int>> &graph, vector<int> &path, int pos, int n) {
    if(pos == n) {
        return graph[path[pos-1]][path[0]] == 1;
    }

    for(int v = 1; v < n; v++) {
        if(isSafe(v, graph, path, pos, n)) {
            path[pos] = v;

            if(hamCycleUtil(graph, path, pos+1, n))
            return true;

            path[pos] = -1;
        }
    }

    return false;
}

void hamcycle(vector<vector<int>> &graph, int n) {
    vector<int> path(n, -1);

    path[0] = 0;

    if(!hamCycleUtil(graph, path, 1, n)) {
        cout << "No hamiltonian cycle" << endl;
        return;
    }

    cout << "Hamiltonian Cycle: ";
    for(int i = 0; i < n; i++) 
    cout << path[i] << " ";

    cout << path[0] << endl;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
        cin >> graph[i][j];
    }

    hamcycle(graph, n);

    return 0;
}