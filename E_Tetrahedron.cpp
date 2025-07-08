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
int n;
int solveMem(int i,int c,vector<vector<int>>& dp){
    if(i==n){
        return c == 3;
    }
    if(dp[i][c]!=-1) return dp[i][c];
    int ans = 0;
    for(int a = 0 ; a <= 3 ; a++  ){
        if(c != a){
            ans = (ans + solveMem(i+1,a,dp))%MOD;
        }
    }
    return dp[i][c] = ans;

}
int solveTab(int n){
    // vector<vector<int>> dp(n+1,vector<int>(4,0));
    vector<int> prev(4,0),curr(4,0);
    curr[3] = 1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=3;j++){
            int ans = 0;
            for(int a = 0 ; a <= 3 ; a++  ){
                if(j != a){
                    ans = (ans + curr[a])%MOD;
                }
            }
            prev[j] = ans;
        }
        curr=prev;
    }
    return prev[3];

}
void solve() {
    cin>>n;

    // vector<vector<int>> dp(n+1,vector<int>(4,-1));
    // int ans = solveMem(0,3,dp);
    int ans = solveTab(n);
    cout<<ans<<endl;
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}