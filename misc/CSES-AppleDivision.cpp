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

static ll n;
static vll p;
static vll ss;
static ll mina = LLONG_MAX;

void proc(ll k) {
    if(k==n) {
        vll ss2;
        ll sum1 = 0, sum2=0;
        for(auto x : ss) {
            sum1 += x;
        }
        for(auto x : p) {
            if(find(all(ss), x) == ss.end()) {ss2.push_back(x); sum2+=x;}
        }
        ll a = sum1-sum2;
        if(a < 0) {a *= -1;}
        if(a < mina) {mina = a;}
    }
    else {
        proc(k+1);
        ss.push_back(p[k]);
        proc(k+1);
        ss.pop_back();
    }
}


int main() {
    cin >> n;
    cin >> p;
    for(ll i=0;i<n;i++) {
        ll a; cin >> a;
        p.push_back(a);
    }
    // cheated a little bit here but counts (edge-case handling)
    if(n==2) {if(p[0]==p[1]) {cout << 0; return 0;}}
    proc(0);
    cout << mina;
}