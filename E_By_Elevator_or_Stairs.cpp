#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];

    vector<ll> res(n);
    vector<ll> dp_stair(n), dp_elev(n);

    dp_stair[0] = 0;
    dp_elev[0] = c;

    res[0] = 0;

    for (int i = 1; i < n; ++i) {
        dp_stair[i] = min(dp_stair[i - 1], dp_elev[i - 1]) + a[i - 1];
        dp_elev[i] = min(dp_elev[i - 1] + b[i - 1], dp_stair[i - 1] + b[i - 1] + c);
        res[i] = min(dp_stair[i], dp_elev[i]);
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }

    cout << '\n';
    return 0;
}
