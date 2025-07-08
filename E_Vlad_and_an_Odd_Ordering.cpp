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

void solve() {
    ll n, k;
        cin >> n >> k;
        int p = 0;
        int nn = n;
        while(k > (nn + 1) / 2) {
            k -= (nn + 1) / 2;
            nn /= 2;
            p++;
        }
        int a = 1 << p;
        int d = 1 << (p + 1);
        cout << a + (k - 1) * d << '\n';

}

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}