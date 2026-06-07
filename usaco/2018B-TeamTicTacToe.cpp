#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int ans1=0, ans2=0;
set<char> iv;
set<string> mv;

void increment(set<char> proc) {
    switch (proc.size()) {
        case 1:
            ans1++;
            iv.insert(*(proc.begin()));
            break;
        case 2:
            ans2++;
            vector<char> curr(2);
            auto it = proc.begin();
            curr[0] = *(it);
            curr[1] = *(++it);
            sort(all(curr));
            mv.insert(string() + curr[0] + curr[1]);
            
            break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("tttt.in","r",stdin);
    freopen("tttt.out","w",stdout);
    vector<vector<char>> grid(3, vector<char>(3));
    for(int i=0;i<3;i++) {for(int j=0;j<3;j++) {cin >> grid[i][j];}}

    // edge cases first
    set<char> pr;
    pr.insert(grid[0][0]);
    pr.insert(grid[1][1]);
    pr.insert(grid[2][2]);
    increment(pr);
    pr.clear();
    pr.insert(grid[2][0]);
    pr.insert(grid[1][1]);
    pr.insert(grid[0][2]);
    increment(pr);
    pr.clear();

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            pr.insert(grid[i][j]);
        }
        increment(pr);
        pr.clear();
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            pr.insert(grid[j][i]);
        }
        increment(pr);
        pr.clear();
    }



    cout << iv.size() << endl << mv.size();
}