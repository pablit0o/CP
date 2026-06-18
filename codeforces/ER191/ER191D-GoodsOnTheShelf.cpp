#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int countBlocks(const vector<int>& a) {
    if(a.empty()) return 0;
    int ct = 1;
    for(int i=1;i<(int)a.size();i++) {
        if(a[i] != a[i-1]) ct++;
    }
    return ct;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        unordered_set<int> s(all(a));
        int size = s.size();

        bool found = false;

        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                swap(a[i], a[j]);

                if(countBlocks(a) == size) {cout << "YES" << endl;found = true;break;}
                swap(a[i], a[j]);
            }
            if(found) break;
        }
        if(!found) {cout << "NO" << endl;}
    }
}