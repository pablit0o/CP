#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b, x; cin >> a >> b >> x;
        vector<pair<ll, ll>> A, B;
        ll cur = a, d = 0;
        while(true) {
            A.push_back({cur, d});
            if(cur == 0){break;}
            cur /= x;
            d++;
        }
        cur = b;
        d = 0;
        while (true) {
            B.push_back({cur, d});
            if(cur == 0) {break;}
            cur /= x;
            d++;
        }
        ll ans = 10000000000000;
        for(auto [u, da] : A) {
            for(auto [w, db] : B) {
                ll v = max(u, w);
                ll diff = da + db + (v - u) + (v - w);
                ans = min(ans, diff);
            }
        }
        cout << ans << endl;
    }
}