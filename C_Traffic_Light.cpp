#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;

        string doubled = s + s; 
        vector<int> next_g(2 * n, -1);
        int last_g = -1;
        for (int i = 2 * n - 1; i >= 0; --i) {
            if (doubled[i] == 'g') last_g = i;
            next_g[i] = last_g;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                int wait_time = next_g[i] - i;
                ans = max(ans, wait_time);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
