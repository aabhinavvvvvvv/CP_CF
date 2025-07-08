#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        for (auto &x : v) cin >> x;

        sort(v.rbegin(), v.rend());
        vector<long long> prefix(n);
        prefix[0] = v[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + v[i];
        }

        while (q--) {
            int a;
            cin >> a;
            int l = 0, r = n - 1, ans = -1;

            while (l <= r) {
                int mid = (l + r) / 2;
                if (prefix[mid] >= a) {
                    ans = mid + 1; 
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            cout << ans << '\n';
        }
    }
    return 0;
}
