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

vs cows = {"Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"};


int main() {
    sort(all(cows));
    unordered_map<string, int> conv;
    for(int i=0;i<cows.size();i++) {
        conv[cows[i]] = i;
    }
    setIO("lineup");
    int n; cin >> n;
    vvi gr(cows.size());
    for(int i=0;i<n;i++) {
        vs inp(6);
        for(int j=0;j<6;j++) {
            cin >> inp[j];
        }
        gr[conv[inp[0]]].push_back(conv[inp[5]]);
        gr[conv[inp[5]]].push_back(conv[inp[0]]);
    }
    vi ans, ones;
    for(int i=0;i<cows.size();i++) {
        switch(gr[i].size()) {
            case 0:
                ans.push_back(i);
                break;
            case 1:
                if(find(all(ones), i) != ones.end()) {continue;}
                ans.push_back(i);
                int prev = i, curr = gr[i][0]; // 3 0
                while(true) {
                    ans.push_back(curr); // 0
                    if(gr[curr].size() == 1) {ones.push_back(curr);break;}
                    if(gr[curr][0] == prev) {
                        prev = curr; 
                        curr = gr[curr][1];
                    }
                    else {
                        prev = curr;
                        curr = gr[curr][0];
                    }
                }
                break;
        }
    }
    for(int i=0;i<ans.size();i++) {
        cout << cows[ans[i]] << endl;
    }
}