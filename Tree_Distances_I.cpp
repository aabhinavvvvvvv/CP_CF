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
void dfs(int node, int parent, vector<vi>& adj, vector<int>& dist) {
    for (auto x : adj[node]) {
        if (x != parent) {
            dist[x] = dist[node] + 1;
            dfs(x, node, adj, dist);
        }
    }
}

void dfs1(int node, int parent, vector<vi>& adj, vector<int>& dist, int d) {
    dist[node] = d;
    for (auto x : adj[node]) {
        if (x != parent) {
            dfs1(x, node, adj, dist, d + 1);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<vi> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> dist1(n, 0);
    dfs(0, -1, adj, dist1);

    int di_st = 0; 
    for (int i = 0; i < n; ++i) {
        if (dist1[i] > dist1[di_st]) {
            di_st = i;
        }
    }

    vector<int> dist2(n, 0);
    dfs(di_st, -1, adj, dist2);

    int di_st2 = di_st; 
    for (int i = 0; i < n; ++i) {
        if (dist2[i] > dist2[di_st2]) {
            di_st2 = i;
        }
    }

    vector<int> dist_from_di_st(n, 0);
    dfs1(di_st, -1, adj, dist_from_di_st, 0);

    vector<int> dist_from_di_st2(n, 0);
    dfs1(di_st2, -1, adj, dist_from_di_st2, 0);

    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        ans[i] = max(dist_from_di_st[i], dist_from_di_st2[i]);
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
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