#include <iostream>
#include <vector>
#include <string>
using namespace std;
int longestSubsequence(string x, string y) {
    int n = x.size(), m = y.size();
    vector<vector<int>> next(n + 1, vector<int>(26, -1));
    vector<int> last(26, -1);

    for (int i = n - 1; i >= 0; --i) {
        last[x[i] - 'a'] = i;
        for (int c = 0; c < 26; ++c)
            next[i][c] = last[c];
    }
    for (int c = 0; c < 26; ++c)
        next[n][c] = -1;

    int maxLen = 0;
    for (int i = 0; i < m; ++i) {
        int pos = 0;
        for (int j = i; j < m; ++j) {
            char c = y[j];
            if (pos >= n || next[pos][c - 'a'] == -1) break;
            pos = next[pos][c - 'a'] + 1;
            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}

int main() {
    string x, y;
    cin >> x >> y;
    cout << longestSubsequence(x, y) << endl;
    return 0;
}