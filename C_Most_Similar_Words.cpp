#include <bits/stdc++.h>
using namespace std;

int calculate_diff(const string &a, const string &b) {
    int diff = 0;
    for (int i = 0; i < a.size(); ++i) {
        diff += abs(a[i] - b[i]);
    }
    return diff;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }

        int min_diff = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                min_diff = min(min_diff, calculate_diff(words[i], words[j]));
            }
        }

        cout << min_diff << '\n';
    }

    return 0;
}
