#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
#define all(x) (x).begin(), (x).end()

template<typename T1, typename T2>
istream& operator>>(istream& in, pair<T1,T2>& p) {
    return in >> p.first >> p.second;
}

template<typename T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto &x : v)
        in >> x;
    return in;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1,T2>& p) {
    return out << p.first << ' ' << p.second;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (const auto& x : v)
        out << x << ' ';
    return out;
}

int main() {
    ll t; cin >> t;
    while(t--) {
        ll n, m; cin >> n >> m;
        vvi ok(m, vi(n));
        ll ct=0;
        for(ll i=0;i<n;i++) {
            for(ll j=0;j<m;j++) {
                cin >> ok[j][i];
            }
        }
        for(ll i=0;i<m;i++) {
            sort(all(ok[i]));
            for(ll j=0;j<n;j++) {
                //num times of sub
                ct += (-1 * ok[i][j]) * (n-j-1);
                ct += ok[i][j] * (j);
            }
        }
        cout << ct << endl;
    }
}