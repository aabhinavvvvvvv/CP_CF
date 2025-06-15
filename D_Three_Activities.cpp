#include <bits/stdc++.h>
using namespace std;

int solve_one_testcase(int n, vector<int>& a, vector<int>& b, vector<int>& c) {
    vector<pair<int, int>> A, B, C;
    for (int i = 0; i < n; ++i) {
        A.emplace_back(a[i], i);
        B.emplace_back(b[i], i);
        C.emplace_back(c[i], i);
    }

    sort(A.rbegin(), A.rend()); 
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    int ans = 0;
    for (int i = 0; i < min(3, n); ++i) {
        for (int j = 0; j < min(3, n); ++j) {
            for (int k = 0; k < min(3, n); ++k) {
                int idx1 = A[i].second;
                int idx2 = B[j].second;
                int idx3 = C[k].second;
                if (idx1 != idx2 && idx1 != idx3 && idx2 != idx3) {
                    int total = A[i].first + B[j].first + C[k].first;
                    ans = max(ans, total);
                }
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        for (int &x : c) cin >> x;
        cout << solve_one_testcase(n, a, b, c) << '\n';
    }

    return 0;
}
