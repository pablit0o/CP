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

bool check(int x, int y, ii posA, ii posB) {
    if(!(x > posA.first && x <= posB.first)) {return false;}
    if(!(y > posA.second && y <= posB.second)) {return false;}
    return true;
}

int main() {
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    vi x(6), y(6); 
    for(int i=0;i<6;i++) {
        cin >> x[i] >> y[i];
    }
    int area = ((x[1]-x[0]) * (y[1]-y[0])) + ((x[3]-x[2]) * (y[3]-y[2]));
    int test=0;
    for(int i=*min_element(all(x));i<=*max_element(all(x));i++) {
        for(int j=*min_element(all(y));j<=*max_element(all(y));j++) {
            // check if in b1/b2
            bool b1 = check(i, j, make_pair(x[0], y[0]), make_pair(x[1], y[1]));
            bool b2 = check(i, j, make_pair(x[2], y[2]), make_pair(x[3], y[3]));
            bool t = check(i, j, make_pair(x[4], y[4]), make_pair(x[5], y[5]));
            if(b1 && t) {
                area--; 
            }
            if (b2 && t) {
                area--; 
            }
        }
    }
    cout << area;
}