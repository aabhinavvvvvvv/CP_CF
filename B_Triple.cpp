#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        unordered_map<int, int> mp;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        int ans = -1;
        for (int x : arr) {
            if (mp[x] >= 3) {
                ans = x;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
