/*
 * Competitive Programming Template
 * Author: Abhinav Gupta
 * GitHub: @abhinav-0107
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
int solveMem(vll& v,int i,int n,vll& dp){
    if(i>n){
        return 0;
    }
    if(i==n){
        return 1;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    ll ans = 1;
    for(int j=2*i;j<=n;j+=i){
        if(v[j] > v[i]){
            ans = max((int)ans,1 + (int)solveMem(v,j,n,dp));
        }
    }
    return dp[i] = ans;
}
int solveTab(vll& v,int n){
    vll dp(n+1,1);
    per(i,n,0){
        ll ans = 1;
        for(int j=2*i;j<=n;j+=i){
            if(v[j] > v[i]){
                ans = max((int)ans,1 + (int)dp[j]);
            }
        }
        dp[i] = ans;
    }
     return *max_element(dp.begin(), dp.end());
}
void solve() {
    ll n;cin>>n;2
    vll v(n+1);
    rep(i,1,n+1){
        cin>>v[i];
    }
    // int ans = 1;
    // vll dp(n+1,-1);
    // for (int i = 1; i <= n; ++i) {
    //     ans = max(ans, solveMem(v, i, n,dp));
    // }
    ll ans = solveTab(v,n);
    cout<<ans<<endl;
}

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}