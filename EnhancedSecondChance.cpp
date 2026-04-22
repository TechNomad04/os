#include <iostream>

using namespace std;

int main() {
    int framesize;
    cout << "Enter Frame Size" << endl;
    cin >> framesize;

    int pages[framesize][2];
    int i ;
    for(i = 0; i < framesize; i++)
    pages[i][0] = -1;

    int tbr = 0;

    int hit = 0, miss = 0;

    while(true) {
        int page;
        cin >> page;
        bool alloc = false;
        for(i = 0; i < framesize; i++) {
            if(pages[i][0] == page) {
                pages[i][1] = 1;
                alloc = true;
                hit++;
            }
        }

        if(!alloc) {
            miss++;

            for(i = 0; i < framesize; i++) {
                if(pages[i][0] == -1) {
                    alloc = true;
                    pages[i][0] = page;
                    pages[i][1] = 1;
                    break;
                }
            }

            if(!alloc) {
                int start = tbr;
                while(pages[tbr][1] != 0){
                    tbr = (tbr+1) %framesize;
                    if(tbr == start)
                    break;
                }

                for(i = 0; i < framesize; i++) 
                pages[i][1] = 0;

                pages[tbr][0] = page;
                pages[tbr][1] = 1;
            }
        }

        cout << "------------------------------------" << endl;

        for(i = 0; i < framesize; i++) {
            cout << pages[i][0] << " : " << pages[i][1] << endl;
        }
        cout << "\n" << "Hit Rate: " << hit <<endl;
        cout << "Miss Rate: " << miss << endl;

        cout << "-------------------------------------" << endl;
    }
}