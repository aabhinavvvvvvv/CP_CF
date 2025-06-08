#include <bits/stdc++.h>
using namespace std;

bool canPassAllDoors(vector<int> &a, int n, int x) {
    for (int start = 0; start < n; ++start) {
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                if (i < start || i >= start + x) {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << (canPassAllDoors(a, n, x) ? "YES" : "NO") << '\n';
    }
    return 0;
}