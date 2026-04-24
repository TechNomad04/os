#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];

            if(i != j && dist[i][j] == 0)
            dist[i][j] = INF;
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    cout << "All-pairs shortest distances:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> eccentricity(n);
    for(int i = 0; i < n; i++) {
        int maxDist = -1;
        for(int j = 0; j < n; j++) {
            if(dist[i][j] != INF) 
            maxDist = max(maxDist, dist[i][j]);
        }

        eccentricity[i] = maxDist;
    }

    cout << "\nEccentricity:\n";
    for(int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": " << eccentricity[i] << endl;
    }

    int radius = *min_element(eccentricity.begin(), eccentricity.end());

    cout << "\nRadius: " << radius << endl;

    cout << "Centre vertices: ";
    for(int i = 0; i < n; i++) {
        if(eccentricity[i] == radius)
            cout << i << " ";
    }
    cout << endl;

    int diameter = *max_element(eccentricity.begin(), eccentricity.end());

    cout << "Diameter: " << diameter << endl;

    return 0;
}