#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Valid Trees:\n";

    for(int n = 1; n <= 100; n++) {  // check reasonable range
        if(n % 4 != 0) continue;     // must be divisible by 4

        if(8 % n != 0) continue;     // ensure k is integer

        int k = 5 - (8 / n);

        if(k <= 1) continue;         // degree must be > 1

        int leaves = (3 * n) / 4;
        int others = n / 4;

        cout << "n = " << n << "\n";
        cout << "Leaves (degree 1): " << leaves << "\n";
        cout << "Other vertices: " << others << " with degree " << k << "\n";
        cout << "-------------------------\n";
    }

    return 0;
}