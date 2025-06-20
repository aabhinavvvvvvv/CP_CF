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

int solveMem(int i,int x,vi& price,vi& pages,int n,vector<vector<int>>& dp){
    if(x==0){
        return 0;
    }
    if(i>=n){
        return INT_MIN;
    }
    if(dp[i][x]!=-1) return dp[i][x];
    int pick = 0;
    if(price[i] <= x){
        pick += pages[i] + solveMem(i+1,x-price[i],price,pages,n,dp);
    }
    int notPick = solveMem(i+1,x,price,pages,n,dp);

    return dp[i][x] = max(pick,notPick);

}
int solveTab(vi& pages,vi& price,int n,int x){
    // vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    vector<int> front(x+1,0),curr(x+1,0);
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=x;j++){
            int pick = 0;
            if(price[i] <= j){
                pick += pages[i] + front[j-price[i]];
            }
            int notPick = front[j];
        
            curr[j] = max(pick,notPick);
        }
        front=curr;
    }
    return curr[x];

}
void solve() {
    int n;cin>>n;
    int x;cin>>x;
    vi price(n);
    each(x,price) cin>>x;
    vi pages(n);
    each(x,pages) cin>>x;
    // vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
    // int ans = solveMem(0,x,price,pages,n,dp);
    int ans = solveTab(pages,price,n,x);
    cout<<ans<<endl;
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}