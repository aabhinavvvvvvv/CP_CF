#include <bits/stdc++.h>
using namespace std;

string solve(int n0, int n1, int n2) {
    string result;

    // Start with n2 block (if any)
    if (n2 > 0)
        result += string(n2 + 1, '1');

    // If both n2 and n0 are zero, handle alternation separately
    if (result.empty() && n0 == 0)
        result += "10", n1--;

    // If result ends in '1' and we need n1 transitions, alternate
    if (n1 > 0) {
        if (result.empty()) {
            // nothing added yet
            result += "0";
            n1--;
        } else if (result.back() == '1') {
            result += '0';
            n1--;
        }
        // Now alternate
        while (n1--) {
            result += result.back() == '0' ? '1' : '0';
        }
    }

    // Now add n0 block if needed
    if (n0 > 0) {
        if (result.empty()) {
            result += string(n0 + 1, '0');
        } else if (result.back() == '1') {
            result += string(n0 + 1, '0');
        } else {
            result += string(n0, '0');
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        cout << solve(n0, n1, n2) << '\n';
    }
    return 0;
}
