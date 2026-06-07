#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    freopen("cowqueue.in","r",stdin);
    freopen("cowqueue.out","w",stdout);
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;i++) {int x, b; cin >> x >> b; a[i] = make_pair(x, b);}
    sort(all(a));

    int tot = a[0].first+a[0].second; // 432
    a.erase(a.begin());

    while(a.size() > 0) {
        vector<pair<int, int>> av;
        for(int j=0;j<a.size();j++) {
            if(tot > a[j].first) {av.push_back(make_pair(a[j].second, a[j].first));}
            else {break;};
        }
        if(av.size() == 0) {
            tot = a[0].first+a[0].second;
            a.erase(a.begin());
            continue;
        }
        sort(all(av));
        tot += av[0].first;
        auto it = find(all(a), make_pair(av[0].second, av[0].first));
        if (it != a.end()) {
            a.erase(it);
        }
    }
    cout << tot;
}