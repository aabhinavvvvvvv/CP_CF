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

vi lvl;
vi parent; 
void dfs(int u, int p, vector<vi>& adj){
    parent[u] = p;
    for(auto x : adj[u]){
        if(x != p){
            lvl[x] = lvl[u] + 1;
            dfs(x, u, adj);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<vi> adj(n);
    // vi deg(n, 0);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // deg[u]++;
        // deg[v]++;
    }

    lvl.assign(n, 0);
    parent.assign(n, -1);
    dfs(n - 1, -1, adj); 

    queue<int> q;
    vi deg(n, 0);
    
    for(int i = 0; i < n - 1; i++){ 
        deg[i] = adj[i].size();
        if(parent[i] != -1) {
            deg[i]--; 
        }
        
        if(deg[i] == 0){ 
            q.push(i);
        }
    }

    vector<pii> ans;
    bool f = lvl[0] % 2;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if((lvl[u] % 2) == f){
            ans.pb({1, -1});
            f = !f;
        }

        ans.pb({2, u});

        ans.pb({1, -1});
        f = !f;

        int p_u = parent[u];
        if(p_u != -1 && p_u != n-1) {
            deg[p_u]--;
            if(deg[p_u] == 0){
                q.push(p_u);
            }
        }
    }

    if (!ans.empty()) {
        ans.pop_back();
    }

    cout << ans.size() << '\n';
    for(auto [x, y] : ans){
        if(y == -1){
            cout << x << '\n';
        } else {
            cout << x << ' ' << (y + 1) << '\n';
        }
    }
}

int main() {
    fastIO();
#ifdef LOCAL
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    auto begin = chrono::high_resolution_clock::now();

    int t = 1;
    cin >> t;
    while (t--) solve();

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;

    return 0;
}