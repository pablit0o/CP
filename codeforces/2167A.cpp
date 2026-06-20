#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        set<int> a1;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a1.insert(a); a1.insert(b); a1.insert(c); a1.insert(d);
        if(a1.size() == 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}