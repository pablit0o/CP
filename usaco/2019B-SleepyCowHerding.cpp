#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    int bmin=0, bmax=0;
    vector<int> a(3); for(int i=0;i<3;i++) {cin >> a[i];}
    vector<int> p = a;
    sort(all(p));
    if(p[0]+1==p[1] && p[1]+1==p[2]) {cout << 0 << endl << 0; return 0;}
    int amax = *max_element(all(a)), amin = *min_element(all(a));
    // min first:
    for(int i=0;i<3;i++) {
        p = a;
        if(amin == a[i] || amax == a[i]) {
            p.erase(remove(all(p), p[i]), p.end());
            if(abs(p[0] - p[1]) == 2) {bmin=1; break;}
            else{bmin=2;}
        }
        else {continue;}
    }
    vector<int> dx(3);

    for(int i=0;i<3;i++) {
        dx[i] = abs(a[i]-a[(i+1)%3]);
    }
    int ab = *max_element(all(dx));

    for(int i=0;i<3;i++) {
        if((a[i] == amin || a[i] == amax) && (a[(i+1)%3] == amin || a[(i+1)%3] == amax)) {continue;}
        bmax = max(bmax, dx[i]-1);
    }
    
    cout << bmin << endl << bmax;
}