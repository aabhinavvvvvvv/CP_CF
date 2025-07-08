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
// int solveMem(vll& v,int x,vll& dp){
//     if(x<0){
//         return 0;
//     }
//     if(x==0){
//         return 1;
//     }
//     if(dp[x]!=-1){
//         return dp[x];
//     }
//     ll ans = 0;
//     rep(i,0,v.size()){
//         ll val = solveMem(v,x-v[i],dp);
//         ans += val;
//     }
//     return dp[x] = ans;
// }
int solveTab(vll& v,ll x ){
    int n = v.size();
    vll dp(x+1,0);
    dp[0] = 1;
    rep(i,1,x+1){
        ll ans = 0;
        rep(j,0,v.size()){
            if(i-v[j] >=0){
                ans = (ans + dp[i - v[j]]) % MOD;
            }
        }
        dp[i] = ans;
    }
    return dp[x];
}
void solve() {
    ll n,x;cin>>n>>x;
    vll v(n);
    each(x,v) cin>>x;
    ll ans =0;
    // vll dp(x+1,-1);
    // ans = solveMem(v,x,dp);
    ans = solveTab(v,x);
    cout<<ans<<endl;
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}