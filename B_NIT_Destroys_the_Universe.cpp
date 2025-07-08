#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    if (all_of(a.begin(), a.end(), [](int x) { return x == 0; })) {
        cout << 0 << '\n';
        return;
    }
    if (none_of(a.begin(), a.end(), [](int x) { return x == 0; })) {
        cout << 1 << '\n';
        return;
    }
    int l = 0, r = n - 1;
    while (l < n && a[l] == 0) l++;
    while (r >= 0 && a[r] == 0) r--;

    bool gap = false;
    for (int i = l; i <= r; ++i) {
        if (a[i] == 0) {
            gap = true;
            break;
        }
    }

    cout << (gap ? 2 : 1) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
