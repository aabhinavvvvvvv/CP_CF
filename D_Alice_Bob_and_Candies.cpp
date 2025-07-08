#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto &x : v) {
            cin >> x;
        }

        int sa = 0, sb = 0, a = 0, b = n - 1;
        bool flag = true;
        int rounds = 0;

        int prevA = 0, prevB = 0;

        while (a <= b) {
            int curr = 0;
            rounds++;
            if (flag) {
                while (a <= b && curr <= prevB) {
                    curr += v[a];
                    a++;
                }
                sa += curr;
                prevA = curr;
            } else {
                while (a <= b && curr <= prevA) {
                    curr += v[b];
                    b--;
                }
                sb += curr;
                prevB = curr;
            }
            flag = !flag;
        }

        cout << rounds << " " << sa << " " << sb << endl;
    }

    return 0;
}
