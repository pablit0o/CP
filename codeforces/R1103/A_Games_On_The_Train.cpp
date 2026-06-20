#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> h(n); for(int i=0;i<n;i++) {cin >> h[i];}
        cout << abs(*max_element(all(h))+1 - *min_element(all(h))) << endl;
    }
}