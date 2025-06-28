#include <bits/stdc++.h>
using namespace std;

#define fastIO() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define vi vector<int>
#define each(x, a) for (auto &x : a)
#define per(i, a, b) for (int i = a; i >= b; --i)
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    each(x, a) cin >> x;

    ll operations = 0;

    for (int i = n - 2; i >= 0; --i) {
        if (a[i] < a[i + 1]) continue;

        while (a[i] >= a[i + 1] && a[i] > 0) {
            a[i] /= 2;
            operations++;
        }
        if (a[i] >= a[i + 1]) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << operations << '\n';
}

int main() {
    fastIO();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
