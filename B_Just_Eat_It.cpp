#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            total += v[i];
        }
        long long sum = 0, maxPrefix = LLONG_MIN;
        for (int i = 0; i < n - 1; i++) {
            sum += v[i];
            maxPrefix = max(maxPrefix, sum);
            if (sum < 0) sum = 0;
        }
        sum = 0;
        long long maxSuffix = LLONG_MIN;
        for (int i = 1; i < n; i++) {
            sum += v[i];
            maxSuffix = max(maxSuffix, sum);
            if (sum < 0) sum = 0;
        }

        if (max(maxPrefix, maxSuffix) >= total)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
