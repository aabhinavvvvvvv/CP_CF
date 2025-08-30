

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
#define fastIO() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void _print(int t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(string t) { cerr << '"' << t << '"'; }
void _print(char t) { cerr << '\'' << t << '\''; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }

template <typename T, typename V> void _print(pair<T, V> p);
template <typename T> void _print(vector<T> v);
template <typename T> void _print(set<T> v);
template <typename T> void _print(multiset<T> v);
template <typename T, typename V> void _print(map<T, V> v);

template <typename T, typename V>
void _print(pair<T, V> p) { cerr << '{'; _print(p.first); cerr << ", "; _print(p.second); cerr << '}'; }
template <typename T>
void _print(vector<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template <typename T>
void _print(set<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template <typename T>
void _print(multiset<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template <typename T, typename V>
void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) _print(i), cerr << " "; cerr << "]"; }

/*
* Bakchodi Mat Kar Laude
* Chup Chap code kar
* I will not be responsible for any damage caused by this code
*/

pair<int,int> delta(char c) {
    if (c == 'U') return {-1, 0};
    if (c == 'D') return {1, 0};
    if (c == 'L') return {0, -1};
    return {0, 1}; 
}
void solve() {
    
    ll Rt, Ct, Ra, Ca;
    ll N; int M, L;
    cin >> Rt >> Ct >> Ra >> Ca;
    cin >> N >> M >> L;

    vector<pair<char, ll>> S(M), T(L);
    for (int i = 0; i < M; ++i) cin >> S[i].first >> S[i].second;
    for (int j = 0; j < L; ++j) cin >> T[j].first >> T[j].second;

    int i = 0, j = 0;
    ll rs = S[0].second, rt = T[0].second;
    auto dS = delta(S[0].first), dT = delta(T[0].first);

    ll ans = 0;
    while (i < M && j < L) {
        ll k = min(rs, rt);

        ll dfr = Rt - Ra;
        ll dfc = Ct - Ca;
        ll dr = dS.first - dT.first;  
        ll dc = dS.second - dT.second;

        if (dr == 0 && dc == 0) {
            if (dfr == 0 && dfc == 0) ans += k;
        } else if (dr == 0) {
            if (dfr == 0) {
                if (dfc % dc == 0) {
                    ll t = -dfc / dc;
                    if (t >= 1 && t <= k) ans++;
                }
            }
        } else if (dc == 0) {
            if (dfc == 0) {
                if (dfr % dr == 0) {
                    ll t = -dfr / dr;
                    if (t >= 1 && t <= k) ans++;
                }
            }
        } else {
            if (dfr % dr == 0 && dfc % dc == 0) {
                ll tr = -dfr / dr;
                ll tc = -dfc / dc;
                if (tr == tc && tr >= 1 && tr <= k) ans++;
            }
        }

        // advance positions by k steps
        Rt += dS.first * k; Ct += dS.second * k;
        Ra += dT.first * k; Ca += dT.second * k;

        rs -= k; rt -= k;
        if (rs == 0) {
            ++i;
            if (i < M) { dS = delta(S[i].first); rs = S[i].second; }
        }
        if (rt == 0) {
            ++j;
            if (j < L) { dT = delta(T[j].first); rt = T[j].second; }
        }
    }

    cout << ans << "\n";
}

int main() {
    fastIO();

    // ✅ Always redirect stderr to Error.txt for debug
    freopen("Error.txt", "w", stderr);

#ifdef LOCAL
    // ✅ Only redirect input/output during local debugging
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}