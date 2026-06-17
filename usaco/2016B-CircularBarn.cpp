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
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    int n, dummyN; cin >> n; dummyN = n;
    vi r(n); cin >> r;
    vi sum(n);
    int okSum = accumulate(all(r), 0);
    for(int i=0;i<n;i++) {
        int curr=0, currSum = okSum, ct=0;
        for(int j=i;ct<n;j++) {
            currSum -= r[j];
            curr += currSum;
            if(j == n-1) {j = -1;}
            ct++;
        }
        dummyN = n;
        sum[i] = curr;
    }
    // 29 -> 22 ->
    // 22 -> 
    cout << *min_element(all(sum));
}