#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int n;
        cin >> n;
        if(n == -1) exit(0);
        vector<pair<int, int>> queries;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                queries.push_back({i, j});
            }
        }
        sort(queries.begin(), queries.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            int d1 = p1.second - p1.first;
            int d2 = p2.second - p2.first;
            if(d1 != d2) return d1 < d2;
            return p1.first < p2.first;
        });
        for(auto& q : queries) {
            cout << q.first << " " << q.second << endl;
            cout.flush();
            int x;
            cin >> x;
            if(x == -1) exit(0);
            if(x == 1) break;
        }
    }
    return 0;
}
