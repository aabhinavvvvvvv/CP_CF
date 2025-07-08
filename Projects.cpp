/*
 * Competitive Programming Template
 * Author: Abhinav Gupta
 * GitHub: @aabhinavvvvvvv
 * MAHAKAL KI JAI
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

/*
 * Bakchodi Mat Kar Laude
 * Chup Chap code kar
 * I will not be responsible for any damage caused by this code
 */

int n;
vector<vector<int>> v;
vector<ll> dp;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

ll solveMem(int i) { 
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];

    ll notTake = solveMem(i + 1);

    int nextIdx = upper_bound(v.begin(), v.end(), v[i][1],
        [](int val, const vector<int>& job) {
            return val < job[0];
        }) - v.begin();

    ll take = v[i][2] + solveMem(nextIdx);

    return dp[i] = max(take, notTake);
}

ll solveTab() {
    for (int i = n - 1; i >= 0; --i) {
        ll notTake = dp[i + 1];

        int nextIdx = upper_bound(v.begin(), v.end(), v[i][1],
            [](int val, const vector<int>& job) {
                return val < job[0];  
            }) - v.begin();

        ll take = v[i][2] + dp[nextIdx];

        dp[i] = max(take, notTake);
    }
    return dp[0];
}


void solve() {
    cin >> n;
    v.resize(n, vector<int>(3));
    dp.assign(n + 1, 0); 

    rep(i, 0, n) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    sort(all(v), compare); 

    cout << solveTab() << '\n';  
}


int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
