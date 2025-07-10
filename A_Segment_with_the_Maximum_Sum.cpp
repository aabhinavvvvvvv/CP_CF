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
struct state {
    ll sum, maxpre, maxsuf, bestsum;

    state(ll val = 0) {
        sum = val;
        maxpre = maxsuf = bestsum = max(0ll,val);
    }
};


state merge( state &a, state &b) {
    state res;
    res.sum = a.sum + b.sum;
    res.maxpre = max(a.maxpre, a.sum + b.maxpre);
    res.maxsuf = max(b.maxsuf, b.sum + a.maxsuf);
    res.bestsum = max({a.bestsum, b.bestsum, a.maxsuf + b.maxpre});
    return res;
}


vector<state> segTree;
vector<int> arr;

void build(int node, int st, int end) {
    if (st == end) {
        segTree[node] = state(arr[st]);  
        return;
    }
    int mid = (st + end) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, end);
    segTree[node] = merge(segTree[2 * node], segTree[2 * node + 1]);
}

void update(int node, int st, int end, int pos, int val) {
    if (st == end) {
        arr[pos] = val;
        segTree[node] = state(val);
        return;
    }
    int mid = (st + end) / 2;
    if (pos <= mid)
        update(2 * node, st, mid, pos, val);
    else
        update(2 * node + 1, mid + 1, end, pos, val);
    segTree[node] = merge(segTree[2 * node], segTree[2 * node + 1]);
}

void solve() {
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    segTree.assign(4 * n, state(-1e18)); 

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    build(1, 0, n - 1);

    cout << max(0LL, segTree[1].bestsum) << "\n"; 

    while (q--) {
        int a;
        ll b;
        cin >> a >> b;
        update(1, 0, n - 1, a, b);
        cout << max(0LL, segTree[1].bestsum) << "\n";
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