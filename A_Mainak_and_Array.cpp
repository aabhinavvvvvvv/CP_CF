#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int ans = INT_MIN;

    for (int i = 1; i < n; ++i) {
        ans = max(ans, a[i] - a[0]);
    }
    for (int i = 0; i < n-1; ++i) {
        ans = max(ans, a[n - 1] - a[i]); 
    }

    for (int i = 0; i < n - 1; ++i) {
        ans = max(ans, a[i] - a[i + 1]);
    }
    
    cout << (ans==INT_MIN? 0 : ans)  << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
