#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if (x % y == 0) {cout << 0 << endl;}
        else {
            int w = x % y;
            cout << y - w << endl;
        }
    }
}