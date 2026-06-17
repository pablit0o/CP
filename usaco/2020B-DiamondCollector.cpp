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
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;
    sort(all(a));
    vi cts;
    for(int i=0;i<n;i++) {
        vi curr; curr.push_back(a[i]);
        for(int j=0;j<n;j++) {
            if(i==j) {continue;}
            bool ok = true;
            for(int z=0;z<curr.size();z++) {
                if(abs(curr[z]-a[j]) > k) {ok=false;break;}
            }
            if(ok) {curr.push_back(a[j]);}
        }
        cts.push_back(curr.size());
    }
    cout << *max_element(all(cts));
}