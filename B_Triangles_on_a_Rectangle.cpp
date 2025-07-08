#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int w, h; cin >> w >> h;
        long long maxArea = 0;

        for (int i = 0; i < 4; i++) {
            int k; cin >> k;
            vector<int> v(k);
            for (auto &x : v) cin >> x;

            int length = v[k - 1] - v[0];
            if (i < 2) {
                maxArea = max(maxArea, 1LL * length * h);
            } else {
                maxArea = max(maxArea, 1LL * length * w);
            }
        }

        cout << maxArea << endl;
    }
    return 0;
}
