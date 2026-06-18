#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        int ans = 1;

        for (int L = n / 2; L >= 1; L--) {
            vector<int> cnt(n + 5, 0);
            multiset<int> ms;
            int distinct = 0;

            auto add = [&](int x) {
                if (cnt[x] == 0) distinct++;
                cnt[x]++;
                ms.insert(x);
            };

            auto remove = [&](int x) {
                cnt[x]--;
                if (cnt[x] == 0) distinct--;
                ms.erase(ms.find(x));
            };

            vector<char> good(n, 0);

            for (int i = 0; i < n; i++) {
                add(a[i]);
                if (i >= L) remove(a[i - L]);

                if (i >= L - 1) {
                    if (distinct == L) {
                        int mn = *ms.begin();
                        int mx = *ms.rbegin();
                        if (mx - mn + 1 == L) {
                            good[i - L + 1] = 1;
                        }
                    }
                }
            }

            vector<char> suf(n + 2, 0);
            for (int i = n - 1; i >= 0; i--) {
                suf[i] = good[i] || suf[i + 1];
            }

            bool ok = false;
            for (int i = 0; i + L < n; i++) {
                if (good[i] && suf[i + L]) {
                    ok = true;
                    break;
                }
            }

            if (ok) {
                ans = L;
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}