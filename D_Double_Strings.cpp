#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> words(n);
    unordered_set<string> st;
    
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        st.insert(words[i]);
    }

    string result;
    for (auto &s : words) {
        bool found = false;
        int len = s.length();
        for (int i = 1; i < len; ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (st.count(left) && st.count(right)) {
                found = true;
                break;
            }
        }
        result += (found ? '1' : '0');
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
