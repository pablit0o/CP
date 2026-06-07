#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    int n, m, ans=0; cin >> n >> m;
    vector<vector<char>> cows(n*2, vector<char> (m));
    for(int i=0;i<n*2;i++) {for(int j=0;j<m;j++) {cin >> cows[i][j];}}
    // N < 500 and M < 50
    for(int i=0;i<m-2;i++) {
        for(int j=i+1;j<m-1;j++) {
            for(int k=j+1;k<m;k++) {
                unordered_set<string> spot;
                for(int z=0;z<n;z++) {spot.insert(string() + cows[z][i] + cows[z][j] + cows[z][k]);}
                int a = spot.size();
                bool found = true;
                for(int z=n;z<n*2;z++) {
                    spot.insert(string() + cows[z][i] + cows[z][j] + cows[z][k]);
                    if(spot.size() == a) {found = false; break;}
                    else{spot.erase(string() + cows[z][i] + cows[z][j] + cows[z][k]);}
                }
                if(found) {ans++;}
            }
        }
    }     

    cout << ans;
}