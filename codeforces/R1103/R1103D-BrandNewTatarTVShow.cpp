#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> t; // stores dp[i] == 0 (losing positions)

    SegTree(int n) : n(n), t(4*n, 0) {}

    void update(int v, int l, int r, int i, int val) {
        if (l == r) {
            t[v] = val;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) update(v*2, l, m, i, val);
        else update(v*2+1, m+1, r, i, val);
        t[v] = t[v*2] + t[v*2+1];
    }

    void update(int i, int val) {
        update(1, 0, n-1, i, val);
    }

    int query(int v, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return t[v];
        int m = (l + r) / 2;
        return query(v*2, l, m, ql, qr)
             + query(v*2+1, m+1, r, ql, qr);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n-1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) v.push_back({a[i], i});
        sort(v.begin(), v.end());

        vector<int> pos(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = v[i].first;
            pos[v[i].second] = i;
        }

        // compute r[i]
        vector<int> r(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && b[j] <= b[i] + k) j++;
            r[i] = j - 1;
        }

        vector<int> dp(n, 0); // 1 = winning, 0 = losing
        SegTree st(n);

        dp[n-1] = 0;
        st.update(n-1, 1);

        for (int i = n-2; i >= 0; i--) {
            int L = i+1, R = r[i];

            // check if there exists losing position in range
            int cntLosing = st.query(L, R);

            if (cntLosing > 0) dp[i] = 1;
            else dp[i] = 0;

            st.update(i, dp[i] == 0);
        }

        // Arseniy condition
        bool ok = false;

        for (int i = 0; i < n; i++) {
            int L = i+1, R = r[i];
            int cntLosing = st.query(L, R);

            // all positions in range must be losing
            if (cntLosing == max(0, R - L + 1)) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}