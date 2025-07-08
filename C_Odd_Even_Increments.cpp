#include <bits/stdc++.h>
using namespace std;

bool solve(const vector<int>& a, int start) {
    int p = a[start] % 2;
    for (int i = start; i < a.size(); i += 2) {
        if (a[i] % 2 != p) return false;
    }
    return true;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        bool odd_parity = solve(a, 0);  
        bool even_parity = solve(a, 1); 

        if (odd_parity && even_parity)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
