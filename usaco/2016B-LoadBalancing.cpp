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
    freopen("balancing.in","r",stdin);
    freopen("balancing.out","w",stdout);
    int n, b; cin >> n >> b;
    vll x(n), y(n);
    vi m;
    for(int i=0;i<n;i++) {cin >> x[i] >> y[i];}
    
    // impl took too while; solved n^3
    for(ll xpos : x) {
        for(ll ypos : y) {
            vi currm(4, 0);
            for(int i=0;i<n;i++) {
                if(xpos-1 > x[i] && ypos-1 > y[i]) {currm[0]++;}
                else if(xpos-1 > x[i] && ypos-1 < y[i]) {currm[1]++;}
                else if(xpos-1 < x[i] && ypos-1 > y[i]) {currm[2]++;}
                else {currm[3]++;}
            }
            m.push_back(*max_element(all(currm)));
        }
    }
    cout << *min_element(all(m));
}