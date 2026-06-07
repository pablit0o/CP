#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int n, k, sum = 0; cin >> k >> n;
    vector<vector<int>> log(k, vector<int>(n));
    for(int i=0;i<k;i++) {for(int j=0;j<n;j++) {cin >> log[i][j];}}
    for(int i=1;i<n;i++) {
        for(int j=i+1;j<=n;j++) {
            set<int> curr;
            for(int z=0;z<k;z++) {
                auto it1 = (find(all(log[z]), i) - log[z].begin());
                auto it2 = (find(all(log[z]), j) - log[z].begin());
                if(it1 < it2) {curr.insert(0);} else if(it1 >it2) {curr.insert(1);}
            }
            sum = (curr.size() == 1) ? sum+1 : sum;
        }
    }
    cout << sum;
}