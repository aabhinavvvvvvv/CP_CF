#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int white_count = 0;
        for (int i = 0; i < k; ++i) {
            if (s[i] == 'W') white_count++;
        }

        int min_white = white_count;

        for (int i = k; i < n; ++i) {
            if (s[i - k] == 'W') white_count--; 
            if (s[i] == 'W') white_count++;     
            min_white = min(min_white, white_count);
        }

        cout << min_white << '\n';
    }
    return 0;
}
