#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
<<<<<<< HEAD
typedef vector<ll> vll;
=======
>>>>>>> abbb858442b817f751d58bf902f3af5f37c71e82

int main() {
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    int n,ct=0; cin >> n;
    string a, b; cin >> a >> b;
    while(a != b) {
        bool cr =  false;
        for(int i=0;i<n;i++) {
            if(a[i] != b[i]) {
                cr = true;
                if(b.substr(i, 1) == "H") {b[i] = 'G';}
                else {b[i] = 'H';}
            }
            else if(cr==true && a[i] == b[i]) {break;}
        }
        ct++;
    }

    cout << ct;
}