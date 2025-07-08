#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string result(k, '1');
        result += string(n - k, '0');

        cout << result << '\n';
    }

    return 0;
}
