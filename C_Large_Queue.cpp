#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int Q;
    cin >> Q;
    deque<pair<long long, long long>> dq; // Each element: (value, count)

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            long long c, x;
            cin >> c >> x;
            dq.push_back({x, c});
        } else if (type == 2) {
            long long k;
            cin >> k;
            long long total_sum = 0;
            while (k > 0) {
                auto& seg = dq.front();
                if (seg.second <= k) {
                    total_sum += seg.first * seg.second;
                    k -= seg.second;
                    dq.pop_front();
                } else {
                    total_sum += seg.first * k;
                    seg.second -= k;
                    k = 0;
                }
            }
            cout << total_sum << '\n';
        }
    }
    
    return 0;
}