#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()

int main() {
    freopen("outofplace.in","r",stdin);
    freopen("outofplace.out","w",stdout);
    int n, ct = 0; cin >> n;
    vi a(n); for(int i=0;i<n;i++) {cin >> a[i];}
    vi p;

    p.push_back(a[0]);
    for(int i=1;i<n;i++) {
        if(a[i] != a[i - 1]) {
            p.push_back(a[i]);
        }
    }
    int inc = -1;
    bool found = false;
    for(int i=0;i<p.size();i++) {
        int temp = p[i];
        p.erase(p.begin()+i);
        if(is_sorted_until(all(p)) == p.end()) {inc = i; found = true;}
        p.insert(p.begin()+i, temp);
        if(found) {break;}
    }
   int res=0;
   for(int i=0;i<p.size();i++) {
        if (p[i] > p[inc] && i < inc) {res++;}
        else if (p[i] < p[inc] && i > inc) {res++;}
   }
   cout << res;
}
