#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()

int main() {
    int n; cin >> n; vi a(n),b(n);
    for(int i=0;i<n;i++) {cin >> a[i];}
    for(int i=0;i<n;i++) {cin >> b[i];}
    int ct=0;
    for(int i : b) {
        if(i!=a[0]) {
            ct++;
        }
        a.erase(find(all(a), i));
    }
    cout << ct;
}