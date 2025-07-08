#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto &val : a) cin >> val;

        int changes = 0;
        int low = a[0] - x;
        int high = a[0] + x;

        for (int i = 1; i < n; ++i) {
            int new_low = a[i] - x;
            int new_high = a[i] + x;
            if (new_high >= low && new_low <= high) {
                low = max(low, new_low);
                high = min(high, new_high);
            } else {
                changes++;
                low = new_low;
                high = new_high;
            }
        }
        cout << changes << '\n';
    }
    return 0;
}
