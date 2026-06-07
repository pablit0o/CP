#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end();

string alph = "abcdefghijklmnopqrstuvwxyz";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("blocks.in","r",stdin);
    freopen("blocks.out","w",stdout);
    int n; cin >> n;
    vector<int> sum(26, 0);
    for(int i=0;i<n;i++) {
        string a, b; cin >> a >> b;
        if(a.length() <= b.length()) {
            for(int j=0;j<a.length();j++) {
                auto curr = b.find(a[j]);
                if(curr != string::npos) {b.erase(curr, 1);}
                sum[alph.find(a[j])]++;
            }
            for(int j=0;j<b.length();j++) {sum[alph.find(b[j])]++;}
        }
        else {
            for(int j=0;j<b.length();j++) {
                auto curr = a.find(b[j]);
                if(curr != string::npos) {a.erase(curr, 1);}
                sum[alph.find(b[j])]++;
            }
            for(int j=0;j<a.length();j++) {sum[alph.find(a[j])]++;}
        }
    }
    for(int i=0;i<26;i++) {cout << sum[i] << endl;}
}