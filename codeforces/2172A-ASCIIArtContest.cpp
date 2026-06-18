#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<ll> n(3);
    cin >> n[0] >> n[1] >> n[2];
    if (abs(*max_element(n.begin(), n.end()) - *min_element(n.begin(), n.end())) >= 10) {
        cout << "check again" << endl;
    } 
    else {
        sort(n.begin(), n.end());
        cout << "final " << n[1];
    }
}