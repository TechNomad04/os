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

    for(i = 0; i < m; i++)
    allocated[i] = -1;

    int j = 0;
    for(i = 0; i < m; i++) {
        int start = j;
        do {
            if(blockSize[j] >= processSize[i]) {
                blockSize[j] -= processSize[i];
                allocated[i] = j;
                j = (j+1)%n;
                break;
            }
            j = (j+1)%n;
        }while(start != j);
    }

    cout << "Process No.\tProcess Size\tBlockNo." << endl;
    for(i = 0; i < m; i++)
    cout << i+1 << "\t\t" << processSize[i] << "\t\t" << allocated[i]+1 << endl;
}