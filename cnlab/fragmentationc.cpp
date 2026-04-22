#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

struct Fragment {
    int size;    // data size
    int offset;  // in 8-byte units
    int mf;
    int id;
};

// Fragmentation function
vector<Fragment> fragmentPacket(int psize, int mtu, int id, int base_offset = 0) {
    vector<Fragment> result;

    int maxdata = mtu - 20;
    int fragSize = (maxdata / 8) * 8;

    int s = psize;
    int off = base_offset;

    while (s > 0) {
        Fragment f;
        f.offset = off;
        f.id = id;

        if (s > fragSize) {
            f.size = fragSize;
            f.mf = 1;
            s -= fragSize;
        } else {
            f.size = s;
            f.mf = 0;
            s = 0;
        }

        result.push_back(f);
        off += fragSize / 8;
    }

    return result;
}

int main() {
    int psize = 4000;
    int id = 55;

    int mtu1 = 1500;
    int mtu2 = 620;

    // 🔹 Router 1 Fragmentation
    cout << "At Router 1:\n";
    vector<Fragment> r1 = fragmentPacket(psize, mtu1, id);

    for (int i = 0; i < r1.size(); i++) {
        cout << "Fragment " << i+1
             << " → Size " << r1[i].size
             << ", Offset " << r1[i].offset
             << " MF=" << r1[i].mf << endl;
    }

    // 🔹 Router 2 Re-fragmentation
    cout << "\nAt Router 2:\n";
    vector<Fragment> r2;

    for (int i = 0; i < r1.size(); i++) {
        vector<Fragment> sub = fragmentPacket(
            r1[i].size,
            mtu2,
            id,
            r1[i].offset   // preserve base offset
        );

        char label = 'a';
        for (auto &f : sub) {
            cout << "Fragment " << i+1 << label++
                 << " → Size " << f.size
                 << ", Offset " << f.offset
                 << " MF=" << f.mf << endl;

            r2.push_back(f);
        }
    }

    // 🔹 Shuffle (out-of-order delivery)
    random_device rd;
    mt19937 g(rd());
    shuffle(r2.begin(), r2.end(), g);

    cout << "\nDelivered (Out of Order):\n";
    for (auto &f : r2) {
        cout << "Size " << f.size
             << ", Offset " << f.offset
             << endl;
    }

    // 🔹 Detect missing fragments
    sort(r2.begin(), r2.end(), [](Fragment a, Fragment b) {
        return a.offset < b.offset;
    });

    bool missing = false;
    int expected = 0;

    for (auto &f : r2) {
        if (f.offset != expected) {
            missing = true;
            break;
        }
        expected += f.size / 8;
    }

    if (missing) {
        cout << "\nMissing fragments detected. Cannot reassemble.\n";
    } else {
        cout << "\nAll fragments received. Reassembling...\n";

        int total = 0;
        for (auto &f : r2) total += f.size;

        cout << "Reassembled Packet Size = " << total << endl;
    }

    return 0;
}