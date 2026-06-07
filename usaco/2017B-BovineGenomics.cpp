#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);

    int n, m, ans=0; cin >> n >> m;
    vector<vector<char>> a(2*n, vector<char>(m));
    for(int i=0;i<2*n;i++) {
        for(int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    
    for(int i=0;i<m;i++) {
        unordered_set<char> curr;
        bool flag=true;
        for(int j=0;j<n;j++) {curr.insert(a[j][i]);}
        int size = curr.size();
        for(int j=n;j<2*n;j++) {
            curr.insert(a[j][i]);
            if(curr.size() == size) {flag=false; break;}
            curr.erase(a[j][i]);
        }
        if(flag==true) {ans++;}
    }

    cout << ans;
}