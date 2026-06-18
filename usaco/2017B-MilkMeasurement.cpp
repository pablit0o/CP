#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    int n, sum=0; cin >> n;
    vector<tuple<int, string, int>> q(n);
    map<string, int> z;
    for(int i=0;i<n;i++) {
        int a; string b, c; cin >> a >> b >> c;
        if(c[0] == '+') {c.erase(0, 1);}
        q[i] = make_tuple(a, b, stoi(c));
        z.insert(make_pair(b, 7));
    }
    sort(all(q));
    vector<set<string>> cows;
    for(int i=0;i<q.size();i++) {
        z[get<1>(q[i])] += get<2>(q[i]);
        if(i == 0 && get<2>(q[i]) > 0) {
            set<string> cd; 
            cd.insert(get<1>(q[i]));
            sum++; 
            cows.push_back(cd); 
            continue;
        }
        int max = 0;
        set<string> ed;
        for(auto it = z.begin(); it != z.end(); it++) {
            if(it->second > max) {
                max = it->second;
            }
        }
        for(auto it = z.begin(); it != z.end(); it++) {
            if(it->second == max) {
                ed.insert(it->first);
            }
        }
        cows.push_back(ed);
        if(cows[i] != cows[i-1]) {sum++;}
    
    }
    cout << sum;
}