#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n+2), b(n+2);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        int ans_no = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[i]) ans_no = max(ans_no, i);
        }

        for (int i = 1; i < n; i++) {
            if (a[i] == a[i+1] || b[i] == b[i+1]) {
                ans_no = max(ans_no, i);
            }
        }

        vector<char> seenA(n+2, 0), seenB(n+2, 0);
        int ans_rem = 0;

        for (int j = n - 1; j >= 1; j--) {
            if ((seenA[a[j]] || seenB[a[j]] || seenA[b[j]] || seenB[b[j]])) {
                ans_rem = max(ans_rem, j);
            }
            seenA[a[j+1]] = 1;
            seenB[b[j+1]] = 1;
        }

        cout << max(ans_no, ans_rem) << "\n";
    }

    return 0;
}
