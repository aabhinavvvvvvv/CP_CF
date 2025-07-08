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
      ll n; 
        cin >> n;
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        vector<pair<ll, ll>> ops;
        for(int pass = 0; pass < n; pass++){
            for(int i = 0; i + 1 < n; i++){
                if(a[i] > a[i + 1]){
                    swap(a[i], a[i + 1]);
                    ops.emplace_back(1, i + 1);
                }
            }
        }
        for(int pass = 0; pass < n; pass++){
            for(int i = 0; i + 1 < n; i++){
                if(b[i] > b[i + 1]){
                    swap(b[i], b[i + 1]);
                    ops.emplace_back(2, i + 1);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                swap(a[i], b[i]);
                ops.emplace_back(3, i + 1);
            }
        }
        cout << ops.size() << "\n";
        for(auto &p : ops) cout << p.first << " " << p.second << "\n";
    }


int main() {
    fastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}