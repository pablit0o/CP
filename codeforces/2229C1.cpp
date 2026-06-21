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
        ll n, k=0; cin >> n;
        vector<bool> a(n);
        for(int i=0;i<n;i++) {
            ll inp; cin >> inp;
            (inp<0) ? a[i]=false : a[i]=true;
        }
        
        // worst 1010101010 -> 001... -> 000 -> n/2 ops..
        // binary-> elems unaffected %2 swaps
        // always do op on ending 1-component
        vll ans, wrong;
        ll curr=-1;
        for(ll i=0;i<n;i++) {
            if(!a[i]) {curr=i;}
            if((a[i]&&(!(a[i+1])))||(i==n-1&&a[i])) {
                wrong.push_back(curr);
                ans.push_back(i);
                k++;
            }
        }
        for(int i=wrong.size()-1;i>=0;i--) {
            if(wrong[i]==-1) {continue;}
            k++; ans.push_back(wrong[i]);
        }


        cout << k << endl;
        for(auto ok : ans) {cout << ok+1 << " ";}
        cout << endl;
    }
}