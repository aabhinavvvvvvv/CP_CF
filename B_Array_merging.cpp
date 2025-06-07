#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> streak_a(2 * n + 1, 0);
        vector<int> streak_b(2 * n + 1, 0);

        int cnt = 1;
        streak_a[a[0]] = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) cnt++;
            else cnt = 1;
            streak_a[a[i]] = max(streak_a[a[i]], cnt);
        }
        cnt = 1;
        streak_b[b[0]] = 1;
        for (int i = 1; i < n; i++) {
            if (b[i] == b[i - 1]) cnt++;
            else cnt = 1;
            streak_b[b[i]] = max(streak_b[b[i]], cnt);
        }
        int ans = 0;
        for (int i = 1; i <= 2 * n; i++) {
            ans = max(ans, streak_a[i] + streak_b[i]);
        }

        cout << ans << endl;
    }
    return 0;
}
