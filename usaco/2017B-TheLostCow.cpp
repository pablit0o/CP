#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("lostcow.in","r",stdin);
    freopen("lostcow.out","w",stdout);
    int x, y, sum = 0; cin >> x >> y;
    int ct = 1, pos = x;
    while(pos != y) { // 0 1000
        int dx = pos;
        pos = (x + ct);
        sum += abs(pos - dx);
        ct *= -2;
        if(x < y && pos > y) {sum -= abs(pos - y); pos = y;}
        if(x > y && pos < y) {sum -= abs(pos - y); pos = y;}
    }
    cout << sum;
}
