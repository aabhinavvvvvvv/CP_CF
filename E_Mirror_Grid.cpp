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

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a; i > b; --i)
#define each(x, a) for (auto &x : a)

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
template <class T> void _print(vector<T> v) {
    cerr << '['; for (auto x : v) { _print(x); cerr << ' '; } cerr << ']';
}

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n;cin>>n;
    vector<string> v(n);
    rep(i,0,n){
        cin >> v[i];
    }

    ll op=0;
    rep(i,0,(n+1)/2){
        rep(j,0,n/2){
            ll x1 = i, y1 = j;
            ll x2 = j, y2 = n - 1 - i;
            ll x3 = n - 1 - i, y3 = n - 1 - j;
            ll x4 = n - 1 - j, y4 = i;

            ll ones = 0;
            ones += v[x1][y1] == '1';
            ones += v[x2][y2] == '1';
            ones += v[x3][y3] == '1';
            ones += v[x4][y4] == '1';
            op+=min(ones,4-ones);
        }
    }
    cout<<op<<endl;

}

int main() {
    fastIO();
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

cp