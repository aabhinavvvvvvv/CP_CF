#include <bits/stdc++.h>
using namespace std;

void solve(string s) {
    int n = s.size();
    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'A']++;
    }

    int odd_freq = 0;
    int odd_char = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            odd_freq++;
            odd_char = i;
        }
    }

    if (odd_freq > 1) {
        cout << "NO SOLUTION";
        return;
    }

    string first_half;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < freq[i] / 2; j++) {
            first_half += (char)(i + 'A');
        }
    }

    string second_half = first_half;
    reverse(second_half.begin(), second_half.end());

    string ans = first_half;
    if (odd_char != -1) {
        ans += (char)(odd_char + 'A');
    }
    ans += second_half;

    cout << ans;
}

int main() {
    string s;
    cin >> s;
    solve(s);
    return 0;
}
 