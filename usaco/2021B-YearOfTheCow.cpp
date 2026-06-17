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

map<string, int> yrs = {
    {"Bessie!!", 0}, 
    {"Tiger", 1}, 
    {"Rabbit", 2}, 
    {"Dragon", 3}, 
    {"Snake", 4}, 
    {"Horse", 5}, 
    {"Goat", 6}, 
    {"Monkey", 7}, 
    {"Rooster", 8}, 
    {"Dog", 9}, 
    {"Pig", 10}, 
    {"Rat", 11}
};

int main(){
    int n; cin >> n;
	map<string, int> cows;
	cows["Bessie"] = 0;
	for(int i=1;i<=n;i++){
		string c1, c2, dir, year, s;
		cin >> c1 >> s >> s >> dir >> year >> s >> s >> c2;

		int age = cows[c2], d;
		(dir == "previous") ? d = -1 : d = 1;
		do {
			age += d;
		} while ((12 + age % 12) % 12 != yrs[year]);
		cows[c1] = age;
	}

	cout << abs(cows["Elsie"]);
}