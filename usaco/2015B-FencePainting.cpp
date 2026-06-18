#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b < c || d < a) {cout << (b - a) + (d - c); return 0;}
    if(d >= b && c <= a) {cout << (d - c); return 0;}
    cout << (max(b, d) - min(a, c));
}