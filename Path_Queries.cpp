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
vector<ll> segtree;
int timerGlobal = 0;
void dfs(int node, int parent, const vector<vi>& adj, vi &intime, vi &outtime, vll &eulertour, vll &a) {
    intime[node] = timerGlobal;
    eulertour[timerGlobal] = a[node];   
    ++timerGlobal;
    for (int v : adj[node]) {
        if (v == parent) continue;
        dfs(v, node, adj, intime, outtime, eulertour, a);
    }
    outtime[node] = timerGlobal;
    eulertour[timerGlobal] = -a[node];  
    ++timerGlobal;
}
void build(int node, int st, int end, const vll &eulertour) {
    if (st == end) {
        segtree[node] = eulertour[st];
        return;
    }
    int mid = (st + end) >> 1;
    build(node << 1, st, mid, eulertour);
    build(node << 1 | 1, mid + 1, end, eulertour);
    segtree[node] = segtree[node << 1] + segtree[node << 1 | 1];
}

void update_point(int node, int st, int end, int idx, ll val) {
    if (st == end) {
        segtree[node] = val;
        return;
    }
    int mid = (st + end) >> 1;
    if (idx <= mid) update_point(node << 1, st, mid, idx, val);
    else update_point(node << 1 | 1, mid + 1, end, idx, val);
    segtree[node] = segtree[node << 1] + segtree[node << 1 | 1];
}

ll query_range(int node, int st, int end, int l, int r) {
    if (r < st || end < l) return 0;
    if (l <= st && end <= r) return segtree[node];
    int mid = (st + end) >> 1;
    return query_range(node << 1, st, mid, l, r) + query_range(node << 1 | 1, mid + 1, end, l, r);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vll a(n);
    rep(i,0,n) cin >> a[i];

    vector<vi> adj(n);
    rep(i,0,n-1){
        int u, v; cin >> u >> v;
        --u; --v;          
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int m = 2 * n;
    vi intime(n), outtime(n);
    vll eulertour(m, 0);

    timerGlobal = 0;
    dfs(0, -1, adj, intime, outtime, eulertour, a);

    segtree.assign(4 * m + 5, 0);
    build(1, 0, m - 1, eulertour);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u; ll x;
            cin >> u >> x;
            --u;
            update_point(1, 0, m - 1, intime[u], x);
            update_point(1, 0, m - 1, outtime[u], -x);
            a[u] = x;
        } else {
            int u; cin >> u; --u;
            ll ans = query_range(1, 0, m - 1, 0, intime[u]);
            cout << ans << '\n';
        }
    }
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