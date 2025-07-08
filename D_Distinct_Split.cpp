#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        unordered_set<char> st;

        for (int i = 0; i < n; i++) {
            st.insert(s[i]);
            prefix[i] = st.size();
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            st.insert(s[i]);
            suffix[i] = st.size();
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, prefix[i] + suffix[i + 1]);
        }

        cout << ans << endl;
    }
    return 0;
}
