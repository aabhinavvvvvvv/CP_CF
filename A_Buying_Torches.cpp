#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        long long total_sticks_needed = k * y + k - 1;
        long long stick_trades =(total_sticks_needed + (x-2)) / (x - 1);

        long long total_trades = stick_trades + k;

        cout << total_trades << '\n';
    }

    return 0;
}
