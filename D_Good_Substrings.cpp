#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int base[2] = {53, 127};
const int MOD[2] = {1000000007, 1000000009};

int main() {
    string s, isGood;
    cin >> s >> isGood;
    int k; cin >> k;
    int n = s.size();

    set<pair<ll, ll>> st;

    for (int i = 0; i < n; i++) {
        ll hash[2] = {0, 0};
        ll pw[2] = {1, 1};
        int bad = 0;

        for (int j = i; j < n; j++) {
            if (isGood[s[j] - 'a'] == '0') bad++;
            if (bad > k) break;

            for (int l = 0; l < 2; l++) {
                hash[l] = (hash[l] + (s[j] - 'a' + 1) * pw[l]) % MOD[l];
                pw[l] = (pw[l] * base[l]) % MOD[l];
            }
            st.insert({hash[0], hash[1]});
        }
    }

    cout << st.size() << '\n';
}
