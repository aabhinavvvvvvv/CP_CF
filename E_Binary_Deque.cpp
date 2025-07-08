#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        vector<int> v(n);
        for (auto &x : v) cin >> x;

        int total1 = accumulate(v.begin(), v.end(), 0);
        if (total1 < s) {
            cout << -1 << endl;
            continue;
        }
        if (total1 == s) {
            cout << 0 << endl;
            continue;
        }
        int maxlen = 0, sum = 0, left = 0;

        for (int right = 0; right < n; right++) {
            sum += v[right];

            while (sum > s) {
                sum -= v[left++];
            }

            if (sum == s) {
                maxlen = max(maxlen, right - left + 1);
            }
        }

        cout << n - maxlen << endl;
    }
    return 0;
}
