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

int main() {
    freopen("censor.in","r",stdin);
    freopen("censor.out","w",stdout);
    string s, t; cin >> s >> t;
    int ct=0, tsize = t.size();
    // 16 vs 3 -> 13
    while(ct < s.size()) {
        // cout << s << endl;
        if(s.substr(ct, tsize) == t) {
            s.erase(ct, tsize);
            ct -= tsize;
            if(ct < 0) {ct = 0;}
        }
        else {ct++;}
    }
    cout << s;
}