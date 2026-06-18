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
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    int n; cin >> n;
    vi a(n), pos(n); cin >> a >> pos;
    vvi ok(4, vi(n));
    ok[0] = pos;
    for(int i=1;i<4;i++) {
        for(int j=0;j<n;j++) {
            int curr = find(all(a), j+1) - a.begin();
            ok[i][curr] = ok[i-1][j];
        }
    }
    for(int i=0;i<n;i++) {
        cout << ok[3][i] << endl;
    }
}