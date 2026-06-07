#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    vector<int> c(3), m(3);
    for(int i=0;i<3;i++) {cin >> c[i] >> m[i];}
    for(int i=0;i<100;i++) {
        //  1 2 3 1 2 3 1 2 3
        int curr = i % 3, aft = (i+1)%3;
        if(m[aft] + m[curr] <= c[aft]) {m[aft] += m[curr]; 
            m[curr] = 0;}
        else {
            m[curr] -= (c[aft] - m[aft]); 
            m[aft] = c[aft];}
    }
    cout << m[0] << endl << m[1] << endl << m[2];
}