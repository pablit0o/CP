/*
Note:
For this problem, I do not consider it complete as I had to
search up how to do large modulo division. While I derived
the answer mathematically + had working implementation for
small n&k, i was getting frustrated since I have never done
modulo division (I assumed it was part of the answer)

since implementation will always be a part of the problem regardless
of how beautiful your answer is; this is not a completed problem. since
the contest is div. 2 it shouldnt matter anyway since its unrated for me,
but Im still dissapointed about this problem.
*/
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
    ll t; cin >> t;
    while(t--) {
        ll n, m, r, c; cin >> n >> m >> r >> c;
        // linear algebra kicked in!
        // n + (n-1) + (n-2) . . 2 + 1 + 0 = n(n+1)/2
        // times m too
        ll x=(n-r+1), y=(m-c+1); 
        ll mod = 998244352; // fermat -1
        // ll ans = ((n*(n+1))/2)+((m*(m+1))/2), mod = 998244353;
        // ll test = ((r*(n+1) - ((r*(r+1))/2))%mod)*((c*(m+1) - ((c*(c+1))/2))%mod);

        // ans = # of submatrices given constraint
        // nvm; asking for COMBINATIONS; so 2^()? (jesus)
        // nm - xy
        ll exp1 = (n%mod)*(m%mod)%(mod), exp2 = (x%mod)*(y%mod)%(mod);
        ll exp = (exp1-exp2+(mod)) % (mod);
        
        // pow is still too big bruh
        // cout << pow(2, exp) << endl;
        ll curr=1, ok=2;
        while(exp>0) { 
            if(exp%2==1) {curr=(__int128_t)curr*ok%(mod+1);}
            ok=(__int128_t)ok*ok%(mod+1);
            exp /= 2;
        }
        cout << curr << endl;
    }
}