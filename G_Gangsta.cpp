#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

#define rep(i,a,b) for(int i=a; i<b; ++i)
#define per(i,a,b) for(int i=a; i>b; --i)
#define each(x,a) for(auto &x : a)

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

#ifdef LOCAL
#define debug(x) cerr << #x << " = "; _print(x); cerr << '\n';
#else
#define debug(x)
#endif

void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(string x) { cerr << '"' << x << '"'; }
void _print(char x) { cerr << '\'' << x << '\''; }
template<class T> void _print(vector<T> v) { cerr << '['; for(auto x : v) { _print(x); cerr << ' '; } cerr << ']'; }

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n;
    cin >> n;
    string s; 
    cin >> s;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; ++i)
        v[i] = v[i - 1] + (s[i - 1] == '0' ? 1 : -1);

    sort(v.begin(), v.end());

    ll pref = 0, abs = 0;
    for (int i = 0; i <= n; ++i) {
        abs += v[i] * i - pref;
        pref += v[i];
    }

    ll ans = 1LL * n * (n + 1) * (n + 2) / 6;

    cout << (ans + abs) / 2 << '\n';
}

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}