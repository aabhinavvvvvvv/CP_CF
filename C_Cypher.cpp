#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    int temp = 0;
    while (temp < n) {
        int op;
        cin >> op;
        int initial = v[temp];
        while (op--) {
            char c;
            cin >> c;
            if (c == 'U') {
                if (initial == 0) {
                    initial = 9;
                } else {
                    initial--;
                }
            } else {
                if (initial == 9) {
                    initial = 0;
                } else {
                    initial++;
                }
            }
        }
        temp++;
        cout << initial << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
cp