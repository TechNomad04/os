#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isConnected(vector<vector<int>> &graph, int n) {
    int start = -1;
    int i, j;
    for(i = 0; i < n; i++) {
        int deg = 0;
        for(j = 0; j < n; j++)
        deg += graph[i][j];

        if(deg > 0) {
            start = i;
            break; 
        }
    }

    if (start == -1)
    return true;
    
    vector<int> visited(n, false);
    visited[start] = true;
    stack<int> dfs;
    dfs.push(visited[start]);

    while(!dfs.empty()) {
        int u = dfs.top();
        dfs.pop();

        for(j = 0; j < n; j++){
            if(graph[u][j] && !visited[j]) {
                visited[j] = true;
                dfs.push(j);
            }
        }
    }

    for(i = 0; i < n; i++) {
        int deg = 0;
        for(j = 0; j < n; j++)
        deg += graph[i][j];

        if(deg > 0 && !visited[i])
        return false;
    }
    
    return true;
}

bool isEulerian(vector<vector<int>> &graph, int n) {
    if(!isConnected(graph, n))
    return false;

    int i, j;
    for(i = 0; i < n; i++) {
        int deg = 0;
        for(j = 0; j < n; j++)
        deg += graph[i][j];

        if(deg % 2 != 0)
        return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int> (n));

    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
        cin >> graph[i][j];
    }
    

    if(isEulerian(graph, n))
    cout << "Eulerian circuit exists" << endl;
    else
    cout << "Eulerian circuit doesn't exist" << endl;
    
    return 0;
}