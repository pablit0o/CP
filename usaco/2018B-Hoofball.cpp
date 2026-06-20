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
    setIO("hoofball");
    int n; cin >> n;
    if(n==1) {cout << 1; return 0;}
    vi a(n); cin >> a;
    sort(all(a));

    vvi gr(n);
    gr[0].push_back(1);
    gr[n-1].push_back(n-2);
    for(int i=1;i<n-1;i++) {
        if(abs(a[i-1]-a[i]) <= abs(a[i+1]-a[i])) {
            gr[i].push_back(i-1);
        }
        else {gr[i].push_back(i+1);}
    }
    // ans: standalone cycles + no-neighbor nodes
    map<int, int> ok;
    for(int i=0;i<n;i++) {
        for(int j=0;j<gr[i].size();j++) {
            //cout << i << " " << gr[i][j] << endl;
            ok[gr[i][j]] = 1;
        }
    }
    int ct=0;
    vi seen;
    for(int i=0;i<n;i++) {
        if(!(ok[i])) {
            ct++;
            seen.push_back(i);
            int prev=i, curr=gr[i][0]; //
            while(true) {
                if(find(all(seen),curr)!=seen.end()) {break;}
                seen.push_back(curr);
                prev = curr;
                curr = gr[curr][0];
            }
        }
    }
    ct += (n-seen.size())/2;
    cout << ct;
}