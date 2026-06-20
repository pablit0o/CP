#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        bool accept = true;
        for (int i=0;i<k;i++) {
            int ones = 0;
            for (int pos=i;pos<n;pos+=k) {
                ones += (s[pos] == '1');
            }
            if (ones % 2) {
                accept = false;
                break;
            }
        }
        cout << (accept ? "YES" : "NO") << endl;
    }
}