#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Bound for number of steps before we assume infinite loop (safe due to modulo k logic)
const int MAX_STEPS = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<ll> p(n);
        vector<int> d(n);
        unordered_map<ll, int> light; // position -> delay

        for (int i = 0; i < n; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
            light[p[i]] = d[i];
        }

        int q;
        cin >> q;
        vector<ll> a(q);
        for (int i = 0; i < q; ++i) cin >> a[i];

        for (int i = 0; i < q; ++i) {
            ll pos = a[i];
            int dir = 1;
            int t = 0;

            set<tuple<ll, int, int>> visited;
            bool escaped = false;

            for (int steps = 0; steps < MAX_STEPS; ++steps) {
                if (pos < 1 || pos > 1e15) {
                    escaped = true;
                    break;
                }

                auto state = make_tuple(pos, dir, t % k);
                if (visited.count(state)) break;
                visited.insert(state);

                if (light.count(pos) && (t % k) == light[pos]) {
                    dir *= -1;
                }

                pos += dir;
                t++;
            }

            cout << (escaped ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
