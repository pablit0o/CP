#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()

vector<string> names = {"Bessie", "Maggie", "Henrietta", "Elsie", "Daisy", "Gertie", "Annabelle"};
vector<string> namesA;

int main() {
    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);
    unordered_map<string, int> c;
    for(string i : names) {
        c[i] = 0;
    }
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        string curr; int amt; cin >> curr >> amt;
        c[curr] += amt;
    }
    int min=9999999;
    for(string i : names) {
        if(c[i] < min) {min = c[i];}
    }
    for(string i : names) {
        if(c[i] == min) {c.erase(i);}
        else namesA.push_back(i);
    }
    if(c.size() == 0) {cout << "Tie"; return 0;}

    min=9999999;
    for(string i : namesA) {
        if(c[i] < min) {min = c[i];}
    }
    vector<string> ans;
    for(string i : namesA) {
        if(c[i] == min) {ans.push_back(i);}
    }

    if(ans.size()>1) {cout << "Tie";}
    else{cout << ans[0];}
}