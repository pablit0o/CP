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

int main() {
    int t; cin >> t;
    while(t--) {
        int n, c,ans=0,ans1=0; cin >> n >> c;
        vi a(n), b(n); cin >> a >> b;
        bool ok=true,ok1=true;
        for(int i=0;i<n;i++) {
            if(a[i]<b[i]) {ok=false;break;}
            ans += (a[i]-b[i]);
        }
        sort(all(a)); sort(all(b)); // assume our reordering is aligned with whatever b is
        for(int i=0;i<n;i++) {
            if(a[i]<b[i]) {ok1=false; break;}
            ans1 += (a[i]-b[i]);
        }
        ans1 += c;
        if(!ok1) {cout << -1 << endl;}
        else if(!ok) {cout << ans1 << endl;}
        else {cout << min(ans, ans1) << endl;}

    }
}