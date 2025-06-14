#include <bits/stdc++.h>
using namespace std;

int solve(const vector<string>& grid, int H, int W) {
    vector<vector<int>> val(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            val[i][j] = (grid[i][j] == '#' ? 1 : -1);

    int ans = 0;

    for (int top = 0; top < H; ++top) {
        vector<int> col(W, 0);
        for (int bottom = top; bottom < H; ++bottom) {
            for (int j = 0; j < W; ++j)
                col[j] += val[bottom][j];

            unordered_map<int, int> freq;
            freq[0] = 1;
            int prefix = 0;
            for (int j = 0; j < W; ++j) {
                prefix += col[j];
                ans += freq[prefix];
                freq[prefix]++;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int H, W;
        cin >> H >> W;
        vector<string> grid(H);
        for (int i = 0; i < H; ++i)
            cin >> grid[i];

        cout << solve(grid, H, W) << '\n';
    }

    return 0;
}
