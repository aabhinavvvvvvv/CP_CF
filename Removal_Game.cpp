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
ll solveMem(int i, int j, vi& v, vector<vector<ll>>& dp){
    if(i > j){
        return 0;
    }
    if(i == j){
        return v[i];
    }
    if(dp[i][j] != INF){
        return dp[i][j];
    }
    ll op1 = v[i] + min(solveMem(i+1, j-1, v, dp), solveMem(i+2, j, v, dp));
    ll op2 = v[j] + min(solveMem(i, j-2, v, dp), solveMem(i+1, j-1, v, dp));

    return dp[i][j] = max(op1, op2);
}
ll solveTab(vi& v, int& n) {
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = v[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            ll op1 = v[i] + min(
                (i + 2 <= j ? dp[i + 2][j] : 0),
                (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0)
            );

            ll op2 = v[j] + min(
                (i <= j - 2 ? dp[i][j - 2] : 0),
                (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0)
            );

            dp[i][j] = max(op1, op2);
        }
    }

    return dp[0][n - 1];
}

void solve() {
    int n;cin>>n;
    vi v(n);
    each(x,v) cin>>x;
    // vector<vector<ll>> dp(n,vector<ll>(n,INF));
    // cout << solveMem(0,n-1,v,dp);
    cout << solveTab(v, n);
    
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}