#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

// Use long long for monster counts and answer to avoid overflow
using ll = long long;

void print_state(ll ans, ll x, const std::multiset<ll>& st) {
    std::cerr << "State -> ans: " << ans << ", combo x: " << x << ", hordes: { ";
    for (ll val : st) {
        std::cerr << val << " ";
    }
    std::cerr << "}" << std::endl;
}

ll cost_to_kill_from_scratch(ll k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return (k / 2) + 1 + (k % 2);
}

void solve() {
    int n;
    std::cin >> n;
    std::multiset<ll> st;
    ll ones_count = 0;

    for (int i = 0; i < n; i++) {
        ll val;
        std::cin >> val;
        if (val == 1) {
            ones_count++;
        } else {
            st.insert(val);
        }
    }

    ll ans = 0;
    ll x = 0; 
    
    std::cerr << "\n--- New Test Case ---" << std::endl;
    print_state(ans, x, st);

    // Stage 1: Clear all hordes of size 1
    if (ones_count > 0) {
        ans += ones_count;
        x += ones_count;
        std::cerr << "Cleared " << ones_count << " hordes of size 1." << std::endl;
        print_state(ans, x, st);
    }
    
    // Stage 2: Main greedy loop
    while (!st.empty()) {
        if (st.size() == 1) {
            std::cerr << "Entering final horde logic." << std::endl;
            ll s = *st.begin();
            if (x >= s) {
                ans++;
                std::cerr << "Final horde (s=" << s << ", x=" << x << "): x >= s. Final ult. Cost +1." << std::endl;
            } else {
                ll rem = s - x;
                if (x == 0) {
                    ll cost = cost_to_kill_from_scratch(s);
                    ans += cost;
                    std::cerr << "Final horde (s=" << s << ", x=0): Kill from scratch. Cost +" << cost << "." << std::endl;
                } else {
                    ll cost = 1 + cost_to_kill_from_scratch(rem);
                    ans += cost;
                    std::cerr << "Final horde (s=" << s << ", x=" << x << "): Use ult, then kill rem=" << rem << ". Cost +" << cost << "." << std::endl;
                }
            }
            break; 
        }

        ll smallest = *st.begin();
        ll largest = *st.rbegin();

        if (x > 0 && x + smallest > largest) {
            std::cerr << "Choice: USE combo (x=" << x << ", s=" << smallest << ", l=" << largest << " -> x+s > l)" << std::endl;
            st.erase(std::prev(st.end()));
            ans++;
            largest -= x;
            x = 0;
            if (largest > 0) {
                st.insert(largest);
            }
        } else {
            std::cerr << "Choice: BUILD combo (x=" << x << ", s=" << smallest << ", l=" << largest << " -> x+s <= l)" << std::endl;
            st.erase(st.begin());
            ans += smallest;
            x += smallest;
        }
        print_state(ans, x, st);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}