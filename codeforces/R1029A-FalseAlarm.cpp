#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> dr(n);
        for(int i=0;i<n;i++) {cin >> dr[i];}
        bool found = false;
        for(int i=0;i<n;i++) {
            if(dr[i] == 1) {
                for(int j=i+x;j<n;j++) {
                    if(dr[j] == 1) {found = true; break;}
                }
            }
            if(found == true) {break;}
        }
        if(found == false) {cout << "YES" << endl;}
        else{cout << "NO" << endl;}
    }
}