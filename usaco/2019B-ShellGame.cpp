#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {cin >> a[i][j];}
    }
    vector<int> sum(3, 0);
    for(int i=0;i<3;i++) {
        int pos = i+1;
        for(int j=0;j<n;j++) {
            if(pos == a[j][0]) {pos = a[j][1];}
            else if(pos == a[j][1]) {pos = a[j][0];} 
            
            if(pos == a[j][2]) {sum[i]++;}
        }
    }
    cout << *max_element(all(sum));
}