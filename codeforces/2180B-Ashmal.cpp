#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long t; cin >> t;
    while(t--) {
        long n; cin >> n;
        string s; cin >> s;
        for(long p = 1; p < n; p++){
            string x; cin >> x;
            string a(s + x), b(x + s);
            s = (a < b ? a : b);
        }

        cout << s << endl;
    }
}