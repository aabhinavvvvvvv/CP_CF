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

vector<int> adj[N];
vector<int> p, h, good, bad, subtree_p;
bool is_possible;

void compute_subtree(int node, int parent) {
    subtree_p[node] = p[node];
    for (int child : adj[node]) {
        if (child == parent) continue;
        compute_subtree(child, node);
        subtree_p[node] += subtree_p[child];
    }
}

void validate(int node, int parent) {
    int total = subtree_p[node];

    if ((total + h[node]) % 2 != 0) {
        is_possible = false;
        return;
    }

    good[node] = (total + h[node]) / 2;
    bad[node] = (total - h[node]) / 2;

    if (good[node] < 0 || bad[node] < 0 || good[node] > total || bad[node] > total) {
        is_possible = false;
        return;
    }

    int sum_good_children = 0;
    int sum_bad_children = 0;

    for (int child : adj[node]) {
        if (child == parent) continue;
        validate(child, node);
        sum_good_children += good[child];
        sum_bad_children += bad[child];
    }

    if (sum_good_children > good[node]) {
        is_possible = false;
    }

    int bad_excluding_own = max(0, bad[node] - p[node]);
    if (bad_excluding_own > sum_bad_children) {
        is_possible = false;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    p.assign(n + 1, 0);
    h.assign(n + 1, 0);
    good.assign(n + 1, 0);
    bad.assign(n + 1, 0);
    subtree_p.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) adj[i].clear();

    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) cin >> h[i];

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    is_possible = true;

    compute_subtree(1, 0);
    validate(1, 0);

    cout << (is_possible ? "YES\n" : "NO\n");
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
    cin >> t;
    while (t--) solve();
    return 0;
}