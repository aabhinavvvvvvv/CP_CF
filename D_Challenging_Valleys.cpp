#include <iostream>
#include <vector>
#include <algorithm> 
void solve() {
    int n;
    std::cin >> n; 
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int valley_segments_count = 0;

    for (int i = 0; i < n; ) {
        bool left_condition_met = (i == 0 || a[i-1] > a[i]);
        int r = i;
        while (r + 1 < n && a[r+1] == a[i]) {
            r++;
        }
        bool right_condition_met = (r == n - 1 || a[r] < a[r+1]);
        if (left_condition_met && right_condition_met) {
            valley_segments_count++;
        }

        i = r + 1;
    }

    if (valley_segments_count == 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) { 
        solve();  
    }
    return 0; 
}
