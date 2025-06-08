#include <bits/stdc++.h>
using namespace std;
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<pair<int, int>> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i].first >> queries[i].second;
            queries[i].first--; // zero-based
        }

        for (auto& query : queries) {
            int i = query.first;
            int x = query.second;
            a[i] = x;

            int max_k = 0;
            set<int> tried;
            for (int tries = 0; tries < 30; ++tries) {
                int idx = rng() % n;
                int val = a[idx];
                if (tried.count(val)) continue;
                tried.insert(val);

                vector<int> prefix(n + 1, 0);
                for (int j = 0; j < n; ++j) {
                    prefix[j + 1] = prefix[j] + (a[j] == val ? 1 : -1);
                }

                int mn = 0;
                for (int j = 1; j <= n; ++j) {
                    max_k = max(max_k, prefix[j] - mn);
                    mn = min(mn, prefix[j]);
                }
            }

            cout << max_k << ' ';
        }

        cout << '\n';
    }

    return 0;
}
