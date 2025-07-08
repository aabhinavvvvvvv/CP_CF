#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> p;
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return false;
        p[rb] = ra;
        return true;
    }
};

class Solution {
public:
    int minimumTimeToSplit(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> poltracine = edges; // as requested

        sort(poltracine.begin(), poltracine.end(), [](auto& a, auto& b) {
            return a[2] < b[2]; // sort by time
        });

        int low = 0, high = 1e9, ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            DSU dsu(n);
            int comps = n;

            for (auto& e : poltracine) {
                if (e[2] > mid) {
                    if (dsu.unite(e[0], e[1])) {
                        comps--;
                    }
                }
            }

            if (comps >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans == -1 ? 0 : ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int n1 = 2;
    vector<vector<int>> edges1 = {{0, 1, 3}};
    int k1 = 2;
    cout << "Test Case 1 Output: " << sol.minimumTimeToSplit(n1, edges1, k1) << "\n"; // Expected: 3

    // Test Case 2
    int n2 = 3;
    vector<vector<int>> edges2 = {{0, 1, 2}, {1, 2, 4}};
    int k2 = 3;
    cout << "Test Case 2 Output: " << sol.minimumTimeToSplit(n2, edges2, k2) << "\n"; // Expected: 4

    // Test Case 3
    int n3 = 3;
    vector<vector<int>> edges3 = {{0, 2, 5}};
    int k3 = 2;
    cout << "Test Case 3 Output: " << sol.minimumTimeToSplit(n3, edges3, k3) << "\n"; // Expected: 0

    return 0;
}
