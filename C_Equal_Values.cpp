#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; ++i) {
            positions[a[i]].push_back(i);
        }

        long long min_cost = LLONG_MAX;
        for (auto &p : positions) {
            int v = p.first;
            vector<int> &pos = p.second;

            int max_block = 1, cur_block = 1;
            for (int i = 1; i < pos.size(); ++i) {
                if (pos[i] == pos[i-1] + 1) {
                    cur_block++;
                } else {
                    cur_block = 1;
                }
                max_block = max(max_block, cur_block);
            }
            int len = max_block;
            long long cost = 0;
            int total = len;
            while (total < n) {
                int add = min(total, n - total);
                cost += 1LL * add * v;
                total += add;
            }
            min_cost = min(min_cost, cost);
        }
        cout << min_cost << '\n';
    }
    return 0;
}
