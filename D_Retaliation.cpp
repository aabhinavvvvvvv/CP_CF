#include <iostream>
#include <vector>
using namespace std;

bool can_explode(const vector<long long>& a, int n) {
    long long a1 = a[0];
    long long a2 = a[1];
    long long numerator = 2 * a1 - a2;
    long long denominator = n + 1;

    if (numerator % denominator != 0) return false;
    long long m = numerator / denominator;
    if (m < 0) return false;

    long long k = a1 - m * n;
    if (k < 0) return false;

    for (int i = 0; i < n; ++i) {
        long long expected = k * (i + 1) + m * (n - i);
        if (a[i] != expected) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        if (can_explode(a, n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
