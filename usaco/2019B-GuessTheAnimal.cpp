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
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    int n; cin >> n;
    vector<vector<string>> inp(n);
    for(int i=0;i<n;i++) {
        string a; int k;
        cin >> a >> k;
        for(int j=0;j<k;j++) {
            string inpa; cin >> inpa;
            inp[i].push_back(inpa);
        }
    }
    vi ct(n, 0);
    for(int i=0;i<n;i++) {
        vi lct;
        for(int j=i+1;j<n;j++) {
            int llct=0;
            for(int z=0;z<inp[i].size();z++) {
                if(find(all(inp[j]), inp[i][z]) != inp[j].end()) {llct++;}
            }
            lct.push_back(llct);
        }
        if(lct.size()!=0) {ct[i] = *max_element(all(lct));}
    }
    cout << *max_element(all(ct))+1;
}