#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0; cin >> n;
    vector<int> x(n), y(n);
    for(int i=0;i<n;i++) {cin >> x[i];}
    for(int i=0;i<n;i++) {cin >> y[i];}
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int dist = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
            ans = (dist > ans) ? dist : ans;
        }
    }
    cout << ans;
}