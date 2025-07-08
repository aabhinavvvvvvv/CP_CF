#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<string> v(n);
        unordered_map<string, int> freq;
        for (int i = 0; i < n; ++i){
            cin >> v[i];
            freq[v[i]]++;

        }

        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            string s = v[i];

            for (char ch = 'a'; ch <= 'k'; ++ch) {
                if (ch != s[0]) {
                    string temp = s;
                    temp[0] = ch;
                    ans += freq[temp];
                }
            }
            for (char ch = 'a'; ch <= 'k'; ++ch) {
                if (ch != s[1]) {
                    string temp = s;
                    temp[1] = ch;
                    ans += freq[temp];
                }
            }

        }

        cout << ans/2 << '\n';
    }
    return 0;
}
