#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowsignal.in","r",stdin);
    freopen("cowsignal.out","w",stdout);
    int m, n, k; cin >> m >> n >> k;
    for(int i=0;i<m;i++) {
        string a; cin >> a;
        string ans = "";
        for(int j=0;j<n;j++) {for(int z=0;z<k;z++) {ans += a[j];}}
        for(int j=0;j<k;j++) {cout << ans << endl;}
    }
}