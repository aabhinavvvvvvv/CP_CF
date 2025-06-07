#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n), p(n + 1, 0);  // p[i] is sum of v[0] to v[i-1]

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            p[i + 1] = p[i] + v[i];  // prefix sum from index 0
        }

        vector<bool> found(n + 1, false); // since 1 ≤ a[i] ≤ n

        // Check all subarrays of length >= 2
        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j <= n; j++) {  // subarray length ≥ 2
                int sum = p[j] - p[i];
                if (sum <= n) found[sum] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (found[v[i]]) ans++;
        }

        cout << ans << endl;
    }
    return 0;
}
