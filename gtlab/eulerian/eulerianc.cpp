#include <iostream>
#include <vector>

using namespace std;

bool isConnected(vector<vector<int>> &graph, int n) {
    vector<bool> visited(n, false);
    
    int start = -1;
    for(int i = 0; i < n; i++) {
        int deg = 0;
        for(int j = 0; j < n; j++)
        deg += graph[i][j];

        if(deg > 0) {
            start = i;
            break;
        }
    }

    if(start == -1)
    return true;

    vector<int> stack;
    stack.push_back(start);
    visited[start] = true;

    while(!stack.empty()) {
        int u = stack.back();
        stack.pop_back();

        for(int v = 0; v < n; v++) {
            if(graph[u][v] && !visited[v]) {
                visited[v] = true;
                stack.push_back(v);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int deg = 0;
        for(int j = 0; j < n; j++) 
        deg += graph[i][j];

        if(deg > 0 && !visited[i])
        return false;
    }

    return true;
}

bool isEulerianCircuit(vector<vector<int>> &graph, int n) {
    if(!isConnected(graph, n)) 
    return false;

    for(int i = 0; i < n; i++) {
        int deg = 0;
        for(int j = 0; j < n; j++) 
        deg += graph[i][j];

        if(deg % 2 != 0)
        return false;
    }

    return true;
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

    if(isEulerianCircuit(graph, n))
    cout << "Eulerian circuit exists" << endl;
    else
    cout << "Eulerian circuit does not exist" << endl;

    return 0;
}