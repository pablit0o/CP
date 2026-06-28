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
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define all(x) (x).begin(), (x).end()
#define input(x) 

struct Edge
{
    int to, weight;
    Edge(int dest, int w):
    to(dest), weight(w)
    {
    }
};

// edge list
// struct Edge{
//     int a, b, w;
//     Edge(int start, int end, int weight):
//     a(start), b(end), w(weight)
//     {
//     }
//     bool operator<(const Edge & e)
//     const{ 
//     return w < e.w;
//     }
// };

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

void setIO(string s = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!s.empty()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}
/*
FIRST SOLVED PROB C!!!
*/
int main() {
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vll p(n + 1), rank(n+1,0);
        
        for(ll i=2;i<=n;i++) {
            cin >> p[i];
            rank[i] = rank[p[i]]+1;
        }
        // 4 -> 5, 6, ; disjoint from parent tree?
        vll mrank(n+1), max1(n+1,-1),max2(n+1,-1);
        for(ll i=1;i<=n;i++) {mrank[i] = rank[i];}
        // large 2 ranks -> form unique
        
        for(ll i=n;i>=2;i--) {
            ll parent = p[i];
            mrank[parent] = max(mrank[parent], mrank[i]);
            ll v = mrank[i];
            if(v > max1[parent]) {
                max2[parent] = max1[parent];
                max1[parent] = v;
            } 
            else if(v > max2[parent]) {max2[parent] = v;}
        }
        ll ans=n;
        for(ll i=1;i<=n;i++) {
            if(max2[i] != -1) {ans += (max2[i]-rank[i]);}
        }
        cout << ans << endl;
    }
}