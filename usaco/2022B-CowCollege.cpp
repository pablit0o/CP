#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main() {
    ll n, max = 0; cin >> n;
    vector<ll> c(n);
    for(ll i=0;i<n;i++) {cin >> c[i]; if(c[i] > max) {max = c[i];}}
    sort(all(c));

    pair<ll, ll> res = make_pair(0, 0);
    
    // 1, 4, 6, 6
    for(ll i=0;i<n;i++) {
        ll amt = c[i] * distance(c.begin()+i, c.end());
        if(amt > res.first) {res.first = amt; res.second = c[i];}
    }
    cout << res.first << " " << res.second;
}