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
    freopen("blist.in","r",stdin);
    freopen("blist.out","w",stdout);
    int n; cin >> n;
    vi s(n), t(n), b(n), ans(1000, 0);
    for(int i=0;i<n;i++) {
        cin >> s[i] >> t[i] >> b[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=s[i];j<=t[i];j++) {
            ans[j] += b[i];
        }
    }
    cout << *max_element(all(ans));
<<<<<<< HEAD
}
=======
}
>>>>>>> abbb858442b817f751d58bf902f3af5f37c71e82
