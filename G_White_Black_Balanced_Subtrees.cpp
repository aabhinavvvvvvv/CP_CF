#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4005;

vector<int> tree[MAXN];
string colors;
int result;

pair<int, int> dfs(int node) {
    int w = (colors[node] == 'W');
    int b = (colors[node] == 'B');

    for (int child : tree[node]) {
        pair<int, int> res = dfs(child);
        w += res.first;
        b += res.second;
    }

    if (w == b)
        result++;

    return {w, b};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        // Clear tree
        for (int i = 1; i <= n; i++) {
            tree[i].clear();
        }

        for (int i = 2; i <= n; i++) {
            int p; cin >> p;
            tree[p].push_back(i);
        }

        cin >> colors;
        colors = " " + colors; // Make 1-indexed

        result = 0;
        dfs(1);

        cout << result << '\n';
    }

    return 0;
}
