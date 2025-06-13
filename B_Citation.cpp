#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &x : A) cin >> x;

    int ans = 0;
    for (int x = 0; x <= n; ++x) {
        int count = 0;
        for (int val : A) {
            if (val >= x) count++;
        }
        if (count >= x) {
            ans = x;
        }
    }

    cout << ans << endl;
    return 0;
}
