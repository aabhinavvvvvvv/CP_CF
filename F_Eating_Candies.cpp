#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto &x : v) {
            cin >> x;
        }

        vector<int> prefix(n), suffix(n);
        int pre = 0, suf = 0;
        for (int i = 0; i < n; i++) {
            pre += v[i];
            prefix[i] = pre;

            suf += v[n - 1 - i];
            suffix[n - 1 - i] = suf;
        }

        int i = 0, j = n - 1;
        int ans = 0;
        while (i < j) {
            if (prefix[i] == suffix[j]) {
                ans = (i + 1) + (n - j);
                i++;
                j--;
            }
            else if (prefix[i] < suffix[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
