#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
 
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
 
        ll beauty = 0;
        vector<ll> upgrades;
 
        for (int i = 0; i < n; ++i) {
            ll x = a[i];
            beauty += __builtin_popcountll(x);
 
            while (true) {
                int pos = __builtin_ctzll(~x); 
                ll cost = 1LL << pos;
                if (k < cost) break;
                upgrades.push_back(cost);
                x += cost;
            }
        }
        sort(upgrades.begin(), upgrades.end());
        for (ll cost : upgrades) {
            if (k >= cost) {
                k -= cost;
                ++beauty;
            } else break;
        }
 
        cout << beauty << '\n';
    }
 
    return 0;
}