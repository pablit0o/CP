#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ans1(n);
        ans1[0] = 2, ans1[n-1] = 1, ans1[1] = 3;
        // 1 2 3 4 5 6 7
        // 2 3 7 4 5 6 1
        if(n > 3) {ans1[2] = n;}
        for(int i=3;i<n-1;i++) {
            ans1[i] = i+1;
        }
        for(int i=0;i<n;i++) {cout << ans1[i] << " ";}
        cout << endl;
    }
}