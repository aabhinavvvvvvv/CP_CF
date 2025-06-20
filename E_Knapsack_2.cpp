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

#ifdef LOCAL
#define debug(x) cerr << #x << " = "; _print(x); cerr << '\n';
#else
#define debug(x)
#endif

template<typename T> void _print(T x) { cerr << x; }
template<typename T, typename V> void _print(pair<T, V> p) {
    cerr << '{'; _print(p.first); cerr << ", "; _print(p.second); cerr << '}';
}
template<typename T> void _print(vector<T> v) {
    cerr << '[';
    for (auto &i : v) _print(i), cerr << ' ';
    cerr << ']';
}
template<typename T> void _print(set<T> s) {
    cerr << '{';
    for (auto &i : s) _print(i), cerr << ' ';
    cerr << '}';
}
template<typename K, typename V> void _print(map<K, V> m) {
    cerr << '{';
    for (auto &p : m) _print(p), cerr << ' ';
    cerr << '}';
}

ll n, W;
vll w, v;
vector<vector<ll>> dp;

ll solveMem(ll i, ll value) {
    if (value == 0) return 0;
    if (i >= n) return INF;
    if (dp[i][value] != -1) return dp[i][value];

    ll ans = solveMem(i + 1, value);
    if (value - v[i] >= 0)
        ans = min(ans, w[i] + solveMem(i + 1, value - v[i])); 

    return dp[i][value] = ans;
}

void solve() {
    cin >> n >> W;
    w.resize(n);
    v.resize(n);
    rep(i, 0, n) cin >> w[i] >> v[i];

    int maxValue = accumulate(all(v), 0);
    dp.assign(n + 1, vector<ll>(maxValue + 1, -1));

    for (int val = maxValue; val >= 0; --val) {
        if (solveMem(0, val) <= W) {
            cout << val << endl;
            return;
        }
    }
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}