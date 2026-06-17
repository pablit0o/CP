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

int valid(vi array, int n) {
    for(int i=0;i<n-1;i++) {
        if(array[i] != array[i+1]) {
            return i;
        }
    }
    return -1;
}

// overloading!!!
vi op(vi grid, int y) {
    for(int i=0;i<=y;i++) {
        (grid[i] == 0) ? grid[i] = 1 : grid[i] = 0;
    }
    return grid;
}

vvi op(vvi grid, int x, int y) { // 4 1
    for(int i=0;i<=x;i++) {
        for(int j=0;j<=y;j++) {
            (grid[i][j] == 0) ? grid[i][j] = 1 : grid[i][j] = 0;
        }
    }
    return grid;
}

int main() {
    freopen("cowtip.in","r",stdin);
    freopen("cowtip.out","w",stdout);

    int n; cin >> n;
    vvi grid(n, vi(n));
    
    // annoying input but we live
    for(int i=0;i<n;i++) {
        string row;
        cin >> row;
        for(int j=0;j<n;j++) {
            grid[i][j] = row[j] - '0';
        }
    }
    
    int ct=0;

    for(int i=n-1;i>=0;i--) {
        int a = valid(grid[i], n); 
        while(a > -1) {
            ct++;
            grid = op(grid, i, a);
            a = valid(grid[i], n);
        }
    }
    vi transpose(n);
    // 101010101
    for(int i=0;i<n;i++) {
        transpose[i] = grid[i][0];
    }
    int a = valid(transpose, n);
    while(a > -1) {
        ct++;
        transpose = op(transpose, a);
        a = valid(transpose, n);
    }
    (transpose[0] == 1) ? ct++ : ct += 0;
    cout << ct;
}