#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), res(n);
    for (int &x : a) cin >> x;

    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        for (int j = 0; j < n; ++j) {
            if (j != i) temp.push_back(a[j]);  
        }

        sort(temp.begin(), temp.end());
        long long score = a[i];
        int count = 0;
        for (int x : temp) {
            if (x <= score) {
                score += x;
                count++;
            } else {
                break;
            }
        }
        res[i] = count;
    }

    for (int x : res) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
