#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
#define all(x) (x).begin(), (x).end()

template<typename T1, typename T2>
istream& operator>>(istream& in, pair<T1,T2>& p) {
    return in >> p.first >> p.second;
}

template<typename T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto &x : v)
        in >> x;
    return in;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1,T2>& p) {
    return out << p.first << ' ' << p.second;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (const auto& x : v)
        out << x << ' ';
    return out;
}

ii conv(int x, int y, int n) {
    // 3, 3 -> 2, 2
    if(x > n/2) {
        x = 1 + (n-x); // 
    }
    if(y > n/2) {
        y = 1 + (n-y);
    }
    x--; y--;
    return make_pair(x, y);
}

int main() {
    int n, u; cin >> n >> u;
    vector<vector<char>> c(n, vector<char>(n)); cin >> c;
    vector<ii> upd(u); cin >> upd;
    // n2
    // check for overlap?
    /*
    2 0 -> if 4 remain, if 3 -> +1 -> decide on 2's and 1's?
    3 4
    */
    vvi canv(n/2, vi(n/2));
    int ct=0;
    for(int z=0;z<u;z++) {
        if(z == 0) {
            for(int i=0;i<n/2;i++) {
                for(int j=0;j<n/2;j++) {
                    int lct=0;
                    if(c[i][j] == '#') {canv[i][j]++;}
                    if(c[(n-1)-i][j] == '#') {canv[i][j]++;}
                    if(c[i][(n-1)-j] == '#') {canv[i][j]++;}
                    if(c[(n-1)-i][(n-1)-j] == '#') {canv[i][j]++;}
                    switch(canv[i][j]) {
                        case 3:
                            ct++;
                            break;
                        case 2:
                            ct += 2;
                            break;
                        case 1:
                            ct++;
                            break;
                    }
                }
            }
            cout << ct << endl;
        }
        
        ii x = conv(upd[z].first, upd[z].second, n); 
        if(c[upd[z].first-1][upd[z].second-1] == '.') {
            c[upd[z].first-1][upd[z].second-1] = '#';
            // 0 1
            canv[x.first][x.second]++;
            switch(canv[x.first][x.second]) {
                case 4:
                    ct--;
                    break;
                case 3:
                    ct--;
                    break;
                case 2:
                    ct++;
                    break;
                case 1:
                    ct++;
                    break;
            }
        }
        else{
            c[upd[z].first-1][upd[z].second-1] = '.';
            canv[x.first][x.second]--;
            switch(canv[x.first][x.second]) {
                case 3:
                    ct++;
                    break;
                case 2:
                    ct++;
                    break;
                case 1:
                    ct--;
                    break;
                case 0:
                    ct--;
                    break;
            }
        }
        cout << ct << endl;
    }
}