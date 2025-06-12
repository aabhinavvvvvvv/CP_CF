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
        vector<tuple<int, int, int>> ops;

        // For rows 2 to n, perform two reversals to rotate by i-1
        for (int i = 2; i <= n; ++i) {
            int k = i - 1;
            ops.emplace_back(i, 1, n);  // full reverse
            ops.emplace_back(i, 1, k);  // partial reverse
        }

        cout << ops.size() << '\n';
        for (auto &[i, l, r] : ops) {
            cout << i << ' ' << l << ' ' << r << '\n';
        }
    }

    return 0;
}
