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
class DSU {
public:
    vector<int> parent, rnk, color, blackreachable;

    DSU(int n) {
        parent.resize(n);
        rnk.assign(n, 0);
        color.assign(n, 0);  // 0 = white, 1 = black
        blackreachable.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void union_sets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;

        if (rnk[pu] < rnk[pv]){
            parent[pu] = pv;
            blackreachable[pv] += blackreachable[pu];
        } else if (rnk[pv] < rnk[pu]) {
            parent[pv] = pu;
            blackreachable[pu] += blackreachable[pv];
        } else {
            parent[pv] = pu;
            rnk[pu]++;
            blackreachable[pu] += blackreachable[pv];
        }
    }

    void toggle(int u) {
        int pu = find(u);
        if (color[u] == 0) {
            color[u] = 1;
            blackreachable[pu]++;
        } else {
            color[u] = 0;
            blackreachable[pu]--;
        }
    }

    bool hasBlack(int u) {
        int pu = find(u);
        return (blackreachable[pu] > 0);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v; cin >> u >> v;
            u--, v--;
            dsu.union_sets(u, v);
        } 
        else if (type == 2) {
            int u; cin >> u;
            u--;
            dsu.toggle(u);
        } 
        else {
            int u; cin >> u;
            u--;
            cout << (dsu.hasBlack(u) ? "Yes\n" : "No\n");
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