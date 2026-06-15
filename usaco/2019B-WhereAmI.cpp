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
    // freopen("whereami.in","r",stdin);
    // freopen("whereami.out","w",stdout);
    int n, k=0; string s; cin >> n >> s;
    for(;k<n;k++) {
        set<string> curr;
        int i=0;
        for(;i<n-k+1;i++) {
            curr.insert(s.substr(i, k));
        }
        if(curr.size() == i) {break;}
        else {curr.clear();}
    }
    cout << k;
}
