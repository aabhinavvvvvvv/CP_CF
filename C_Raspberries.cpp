#include <bits/stdc++.h>
using namespace std;

int get_cost(int num, int k) {
    for (int i = 0; i <= 10; i++) {
        if ((num + i) % k == 0) return i;
    }
    return INT_MAX;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int product = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            product = (product * a[i]) % k;
        }

        if (product % k == 0) {
            cout << 0 << endl;
            continue;
        }

        int min_cost = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int temp = a[i];
            int cost = 0;
            for (int j = 1; j <= 10; ++j) {
                temp++;
                cost++;
                int new_product = 1;
                for (int l = 0; l < n; ++l) {
                    if (l == i) new_product = (new_product * temp) % k;
                    else new_product = (new_product * a[l]) % k;
                }
                if (new_product % k == 0) {
                    min_cost = min(min_cost, cost);
                    break;
                }
            }
        }
        cout << min_cost << endl;
    }
    return 0;
}
