#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);

    int count = 0;
    while (a < b) {
        a = a * 2;
        count++;
    }

    if (a != b) {
        cout << "-1\n";
        return;
    }

    int ans = count / 3;
    count %= 3;
    ans += count / 2;
    count %= 2;
    ans += count;

    cout << ans << '\n';
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
