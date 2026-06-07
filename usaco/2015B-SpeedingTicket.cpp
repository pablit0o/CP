#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    vector<short> sp, curr;
    int n, m, max=0, seen=0; cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a, b; cin >> a >> b;
        for(int j=seen;j<seen+a;j++) {sp.push_back(b);}
        seen += a;
    }
    seen = 0;
    for(int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        for(int j=seen;j<seen+a;j++) {curr.push_back(b);}
        seen += a;
    }
    for(int i=0;i<100;i++) {
        if(curr[i] - sp[i] > max) {max = curr[i] - sp[i];}
    }
    cout << max;
}