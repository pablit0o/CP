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
    int n; cin >> n;
    vi a(n); cin >> a;
    int ct=0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            int sum = accumulate(a.begin()+i, a.begin()+j+1, 0);
            if(sum % (j-i+1) != 0) {continue;}
            sum /= (j-i+1);
            if(find(a.begin()+i, a.begin()+j+1, sum) != a.begin()+j+1) {ct++;}
        }
    }
    cout << ct;
}
