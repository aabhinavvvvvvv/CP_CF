#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compute_gcd(const vector<int>& a) {
    int g = a[0];
    for (int num : a) {
        g = __gcd(g, num);
        if (g == 1) {
            break; // GCD can't be smaller than 1
        }
    }
    return g;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int g = compute_gcd(a);
        int count_g = 0;
        for (int num : a) {
            if (num == g) {
                count_g++;
            }
        }

        if (count_g > 0) {
            cout << n - count_g << '\n';
        } else {
            cout << n + 1 << '\n';
        }
    }

    return 0;
}