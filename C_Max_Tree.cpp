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
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a; i > b; --i)
#define each(x, a) for (auto &x : a)
#define sz(x) (int)(x).size()
#define fastIO()                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);

#define debug(x)         \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << endl;

void _print(int t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(string t) { cerr << '"' << t << '"'; }
void _print(char t) { cerr << '\'' << t << '\''; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }

template <typename T, typename V>
void _print(pair<T, V> p);
template <typename T>
void _print(vector<T> v);
template <typename T>
void _print(set<T> v);
template <typename T>
void _print(multiset<T> v);
template <typename T, typename V>
void _print(map<T, V> v);

template <typename T, typename V>
void _print(pair<T, V> p)
{
    cerr << '{';
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << '}';
}
template <typename T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
        _print(i), cerr << " ";
    cerr << "]";
}
template <typename T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
        _print(i), cerr << " ";
    cerr << "]";
}
template <typename T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
        _print(i), cerr << " ";
    cerr << "]";
}
template <typename T, typename V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
        _print(i), cerr << " ";
    cerr << "]";
}

using state = tuple<int, int, int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        long long x, y;
        cin >> u >> v >> x >> y;
        if (x > y)
            g[u].push_back(v);
        else
            g[v].push_back(u);
    }

    vector<int> indeg(n + 1, 0);
    for (int u = 1; u <= n; u++)
    {
        for (int v : g[u])
            indeg[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : g[u])
        {
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    vector<int> p(n + 1);
    int val = n;
    for (int u : topo)
    {
        p[u] = val--;
    }

    for (int i = 1; i <= n; i++)
        cout << p[i] << " ";
    cout << "\n";
}

int main()
{
    fastIO();
#ifdef LOCAL
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    auto begin = chrono::high_resolution_clock::now();

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;

    return 0;
}