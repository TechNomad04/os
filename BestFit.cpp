#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cout << "Enter number  of blocks" << endl;
    cin >> n ;
    cout << "Enter number of processes" << endl;
    cin >> m;

    int blockSize[n], processSize[m];

    int i;
    cout << "Enter block sizes" << endl;
    for(i = 0; i < n; i++)
    cin >> blockSize[i];

    cout << "Enter proccess sizes" << endl;
    for(i = 0; i < m; i++) 
    cin >> processSize[i];

    int allocated[m];

    int j;
    for(i = 0; i < m; i++) {
        int mini = INT_MAX, index = -1;
        for(j = 0; j < n; j++) {
            if(blockSize[j] >= processSize[i] && blockSize[j] < mini) {
                index = j;
                mini = blockSize[j];
            }
        }

        if (index != -1) {
            allocated[i] = index;
            blockSize[index] -= processSize[i];
        } else
        allocated[i] = -1;
    }

    cout << "Process No.\tProcess Size\tBlockNo." << endl;
    for(i = 0; i < m; i++)
    cout << i+1 << "\t\t" << processSize[i] << "\t\t" << allocated[i]+1 << endl;
}