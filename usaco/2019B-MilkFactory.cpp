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

vi dfs(int st, vvi gr, vi ct) {
    for(int i=0;i<gr[st].size();i++) {
        int curr=gr[st][i];
        ct[curr]++;
        ct = dfs(curr, gr, ct);
    }
    return ct;
}



int main() {
    setIO("factory");
    int n; cin >> n;
    vi ct(n, 0);
    vvi gr(n);
    for(int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        gr[a-1].push_back(b-1);
    }
    for(int i=0;i<n;i++) {
        if(gr[i].size()==0) {continue;}
        ct = dfs(i, gr, ct);
    }

    bool ok=false;
    for(int i=0;i<n;i++) {
        if(ct[i]>=n-1) {cout << i+1; ok=true;}
    }
    if(!ok) {cout << -1;}
}