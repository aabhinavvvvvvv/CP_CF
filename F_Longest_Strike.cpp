#include <bits/stdc++.h>
using namespace std;

int balanced_subtrees = 0;

pair<int,int> dfs(int u, const vector<vector<int>>& adj, const string& colors) {
    // Returns pair: {count_black, count_white} in subtree of u
    int black_count = 0, white_count = 0;
    
    if (colors[u-1] == 'B') black_count++;
    else white_count++;
    
    for (int v : adj[u]) {
        auto [b, w] = dfs(v, adj, colors);
        black_count += b;
        white_count += w;
    }
    
    if (black_count == white_count) balanced_subtrees++;
    
    return {black_count, white_count};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj(n+1);
        for (int i = 2; i <= n; i++) {
            int p; cin >> p;
            adj[p].push_back(i);
        }
        string colors; cin >> colors;

        balanced_subtrees = 0;
        dfs(1, adj, colors);

        cout << balanced_subtrees << "\n";
    }
    return 0;
}
