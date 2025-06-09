#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int d; cin >> d;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    sort(v.rbegin(), v.rend());
    int rem = n;
    int ans = 0;
    int i = 0;
    while (i < n && rem > 0) {
        int stats = v[i];
        int k = (d + stats) / stats; 

        if (rem >= k) {
            ans++;
            rem -= k;
            i++;
        } else {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
