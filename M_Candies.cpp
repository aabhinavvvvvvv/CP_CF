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
int solveMem(int i, int k,vi& v,vector<vector<int>>& dp) {
    if (k < 0) return 0;
    if (i == v.size()) return (k == 0);
    if (dp[i][k] != -1) return dp[i][k];

    int ways = 0;
    for (int give = 0; give <= v[i] && give <= k; ++give) {
        ways = (ways + solveMem(i + 1, k - give,v,dp)) % MOD;
    }

    return dp[i][k] = ways;
}
int solveTab(vi& v,int n,int k){
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    dp[n][0]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            int ways = 0;
            for (int give = 0; give <= v[i] && give <= j; ++give) {
                ways = (ways + dp[i+1][j-give])% MOD;
            }
        
            dp[i][j] = ways;
        }
    }
    return dp[0][k];

}
void solve() {
    int n,k;cin>>n>>k;
    vi v(n);
    each(x,v) cin>>x;
    // vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    // int ans = solveMem(0,k,v,dp);
    int ans = solveTab(v,n,k);
    cout<<ans<<endl;
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}