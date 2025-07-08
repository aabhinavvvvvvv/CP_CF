/*
 * Competitive Programming Template
 * Author: Abhinav Gupta
 * GitHub: @aabhinavvvvvvv
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define per(i,a,b) for(int i=a; i>b; --i)
#define each(x,a) for(auto &x : a)
#define sz(x) (int)(x).size()

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

map<ll, ll> d;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    d.clear();

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        d[a[i]]++;
    }

    ll p = (1LL << 31) - 1;
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        if (d[a[i]] == 0) continue;

        ll mask = p & (~a[i]);

        d[a[i]]--;
        bool found = false;

        for (auto &ad: d) {
            if (ad.second > 0 && (ad.first & a[i]) == 0) {
                d[ad.first]--;
                found = true;
                break;
            }
        }

        ans++;
    }

    cout << ans << '\n';
}

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
