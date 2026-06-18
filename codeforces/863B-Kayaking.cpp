#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int getCount(int i, int j, vector<int> ogw) {
    int sum=0;
    vector<int> w = ogw;
    auto it1 = find(all(w), ogw[i]);
    w.erase(it1);

    auto it2 = find(all(w), ogw[j]);
    w.erase(it2);

    for(int x=0;x<w.size();x++) {
        sum += abs(w[x]-w[x+1]);
        x++;
    }
    return sum;
}

int main() {
    int n; cin >> n;
    vector<int> w(n*2);
    for(int i=0;i<n*2;i++) {cin >> w[i];}
    // 1 3 4 6 3 4 100 200
    // 1 3 3 4 4 6 100 200
    // obs: after 2 w/largest difference compared to other entries eliminated -> rest is ez
    sort(all(w));
    
    int min = 100000;
    for(int i=0;i<(n*2)-1;i++) {
        for(int j=i+1;j<n*2;j++) {
                int curr = getCount(i, j, w);
                if(curr < min) {min = curr;}
        }
    }
    cout << min;
}