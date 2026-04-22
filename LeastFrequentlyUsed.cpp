#include <iostream>
#include <map>

using namespace std;

int main() {
    int framesize;
    cout << "Enter Frame size" << endl;
    cin >> framesize;

    int pages[framesize];
    int i;
    for(i = 0; i < framesize; i++)
    pages[i] = -1;
    int hit = 0, miss = 0;

    map<int, int> m;
    int c = 0;

    while(true) {
        int page;
        cin >> page;
        int j;
        bool alloc = false;
        int tbr = -1;
        int mini = __INT_MAX__;
        for(j = 0; j < framesize; j++) {
            if(pages[j] == page) {
                alloc = true;
                m[page] = c++;
                hit++;
                break;
            } else if(pages[j] == -1 || m[pages[j]] < mini) {
                tbr = j;
                mini = m[pages[j]];
            }
        }
        
        if (!alloc) {
            alloc = true;
            m[page] = c++;
            pages[tbr] = page;
            miss++; 
        }

        for(i = 0; i < framesize; i++) {
            cout << pages[i] << endl;
        }

        cout << "Miss Rate: " << miss << endl;
        cout << "Hit Rate: " << hit << endl;
    }
}