#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n*4, 0);
        int left = 4*n;
        vector<set<vector<int>::difference_type>> p(n);

        while(left > 0) {
            for(int i=1;i<=n;i++) {
                vector<int>::iterator it = find(all(a), i);
                vector<int>::iterator itr = a.end();
                auto rit = find(a.rbegin(), a.rend(), i);
                if(rit != a.rend()) itr = rit.base() - 1;

                if(it == a.end()) {
                    for(int j=0;j<n*4;j++) {if (a[j]==0) {a[j]=i; left--; break;}}
                }
                else{
                    for(int j=0;j<n*4;j++) {
                        if(a[j]!=0){continue;}
                        vector<int>::iterator itc = a.begin()+j;
                        std::vector<int>::difference_type dist = itc - itr;
                        int csize = p[i-1].size();
                        p[i-1].insert(dist);
                        if(p[i-1].size() != csize) {a[j]=i;left--; break;}
                    }
                }
            }
        }

        for(int i=0;i<n*4;i++) {cout << a[i] << " ";}
        cout << endl;
    }
}