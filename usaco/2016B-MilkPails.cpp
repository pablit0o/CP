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
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);
    int x, y, m; cin >> x >> y >> m;
    vi ok;
    for(int i=1;i<=(m/x);i++) {
        int curr = i*x;
        while(m - curr >= y) {
            curr += y;
        }
        ok.push_back(curr);
    }

    for(int i=1;i<=(m/y);i++) {
        int curr = i*y;
        while(m - curr >= x) {
            curr += x;
        }
        ok.push_back(curr);
    }


    cout << *max_element(all(ok));
}