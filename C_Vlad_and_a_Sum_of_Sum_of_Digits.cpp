#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
long long digitSum[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < MAXN; ++i) {
        int x = i;
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        digitSum[i] = digitSum[i - 1] + sum;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << digitSum[n] << '\n';
    }

    return 0;
}
