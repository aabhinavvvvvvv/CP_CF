#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool ok = true;
        for (int i = 0; i < n; ) {
            if (s[i] == 'W') {
                i++;
                continue;
            }
            int st = i;
            int cnt_r = 0, cnt_b = 0;
            while (st < n && s[st] != 'W') {
                if (s[st] == 'R') cnt_r++;
                if (s[st] == 'B') cnt_b++;
                st++;
            }
            if (cnt_r == 0 || cnt_b == 0) {
                ok = false;
                break;
            }
            i = st;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
