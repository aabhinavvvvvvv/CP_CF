#include <bits/stdc++.h>
using namespace std;

int N, H, M;
vector<pair<int, int>> monsters;
map<tuple<int, int, int>, int> memo;

int dfs(int i, int h, int m) {
    if (i == N) return 0;

    auto key = make_tuple(i, h, m);
    if (memo.count(key)) return memo[key];

    int A = monsters[i].first;
    int B = monsters[i].second;

    int res = 0;

    // Option 1: Use magic if possible
    if (m >= B) {
        res = max(res, 1 + dfs(i + 1, h, m - B));
    }

    // Option 2: Use health if possible
    if (h >= A) {
        res = max(res, 1 + dfs(i + 1, h - A, m));
    }

    // Option 3: Cannot defeat this monster
    memo[key] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> H >> M;
    monsters.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> monsters[i].first >> monsters[i].second;
    }

    cout << dfs(0, H, M) << "\n";
    return 0;
}
