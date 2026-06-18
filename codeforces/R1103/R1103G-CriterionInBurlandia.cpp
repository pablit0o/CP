#include <bits/stdc++.h>
using namespace std;

static const int MAXA = 500000;
static const int MOD = 1e9 + 7;

int spf[MAXA + 1];

void build_spf() {
    for (int i = 2; i <= MAXA; i++) {
        if (!spf[i]) {
            for (int j = i; j <= MAXA; j += i)
                if (!spf[j]) spf[j] = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_spf();

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (auto &v : a) cin >> v;

        unordered_map<int,int> cnt;

        for (int v : a) {
            unordered_set<int> used_primes;

            while (v > 1) {
                int p = spf[v];
                used_primes.insert(p);
                while (v % p == 0) v /= p;
            }

            for (int p : used_primes)
                cnt[p]++;
        }

        long long ans = 1;
        for (auto &it : cnt) {
            ans = ans * it.second % MOD;
        }

        cout << ans << "\n";
    }

    return 0;
}