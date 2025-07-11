#include <bits/stdc++.h>
using namespace std;

long long computeMaxSubarraySum(const vector<long long>& arr) {
    long long max_sum = 0;
    long long current_sum = 0;
    for (long long num : arr) {
        current_sum += num;
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
        if (current_sum < 0) {
            current_sum = 0;
        }
    }
    return max_sum;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N, X;
        long long P;
        cin >> N >> X >> P;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        long long max_result = 0;
        // We need to choose X positions to add P, others subtract P.
        // The optimal is likely a window of X elements.
        // Try all possible windows of size X.
        for (int start = 0; start <= N - X; ++start) {
            int end = start + X;
            vector<long long> modifiedA = A;
            for (int i = 0; i < N; ++i) {
                if (i >= start && i < end) {
                    modifiedA[i] += P;
                } else {
                    modifiedA[i] -= P;
                }
            }
            long long current_max = computeMaxSubarraySum(modifiedA);
            if (current_max > max_result) {
                max_result = current_max;
            }
        }
        cout << max_result << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}