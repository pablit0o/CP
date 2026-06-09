#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    int t; cin >> t;
    while(t--) {
        int n, x, y, z; cin >> n >> x >> y >> z;
        
        int nor = ceil(float(n) / (x + y)); 
        int AI = 0;
        int i=0;
        for(;AI<n;i++) {
            AI += x;
            if(i < z) {continue;}
            AI += 10*y;
        }


        cout << min(nor, i) << endl;
    }
}