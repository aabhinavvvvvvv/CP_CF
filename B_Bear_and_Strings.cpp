#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    const int n = (int)s.size();
    long long totalSubstrings = 0;
    int lastBearIndex = -1;  // tracks last index where "bear" started

    for (int i = 0; i + 3 < n; ++i) {
        // Check if "bear" starts at i
        if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r') {
            // Number of possible starting positions for substrings containing this "bear"
            int startOptions = i - lastBearIndex;
            // Number of possible ending positions for substrings containing this "bear"
            int endOptions = n - (i + 3);

            totalSubstrings += 1LL * startOptions * endOptions;
            lastBearIndex = i;  // Update last bear start
        }
    }

    cout << totalSubstrings << "\n";
    return 0;
}
