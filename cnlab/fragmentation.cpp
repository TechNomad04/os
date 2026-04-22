#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;


int main() {
    int psize, mtu, idno;
    cin >> psize >> mtu >> idno;

    int maxdata = mtu-20;
    int fragmentdatasize = floor(maxdata/8)*8;

    if(psize > fragmentdatasize) {
        vector<int> size, offset, mf, id;
        int s = psize;
        int off = 0;
        while(s > 0) {
            offset.push_back(off);
            if(s > fragmentdatasize) {
                size.push_back(fragmentdatasize);
                mf.push_back(1);
                s = s-fragmentdatasize;
            }
            else {
                size.push_back(s);
                mf.push_back(0);
                s = 0;
            }
            off = off+(fragmentdatasize)/8;
            id.push_back(idno);
        }

        for(int i = 0; i < size.size(); i++) {
            cout << i+1 << "\t" << id[i] << "\t" << size[i] << "\t" << offset[i] << "\t" << mf[i] << endl;
        }

         srand(time(0));

        vector<int> arr;
        for(int i = 0; i < size.size(); i++)
        arr.push_back(i);

        for (int i = arr.size()-1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }

        vector<int>nsize(arr.size()),noffset(arr.size()), nmf(arr.size()), nid(arr.size());
        for(int i = 0; i < arr.size(); i++) {
            nsize[i] = size[arr[i]];
            noffset[i] = offset[arr[i]];
            nmf[i] = mf[arr[i]];
            nid[i] = id[arr[i]];
        }

        for(int i = 0; i < size.size(); i++) {
            cout << i+1 << "\t" << nid[i] << "\t" << nsize[i] << "\t" << noffset[i] << "\t" << nmf[i] << endl;
        }

        vector<int> idx(arr.size());
        for (int i = 0; i < arr.size(); i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if(id[a] < id[b])
            return nid[a] < nid[b];
            else
            return noffset[a] < noffset[b];
        });

        for(int i; i < idx.size(); i++) {
            id[i] = nid[idx[i]];
            size[i] = nsize[idx[i]];
            offset[i] = noffset[idx[i]];
            mf[i] = nmf[idx[i]];
        }

        for(int i = 0; i < size.size(); i++) {
            cout << i+1 << "\t" << id[i] << "\t" << size[i] << "\t" << offset[i] << "\t" << mf[i] << endl;
        }
    }

    
}