#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;
        int min_r = r / (b + 1);      
        int extra_r = r % (b + 1);    

        string res = "";
        for (int i = 0; i < b + 1; ++i) {
            res += string(min_r, 'R');
            if (extra_r > 0) {
                res += 'R';
                extra_r--;
            }
            if (i < b) res += 'B';
        }

        cout << res << '\n';
    }

    return 0;
}
