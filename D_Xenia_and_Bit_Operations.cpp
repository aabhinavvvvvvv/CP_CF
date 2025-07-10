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

vector<int> segTree, arr;
ll merge(int a,int b, int st, int end){
    int len = end - st + 1;
     if(__builtin_popcountll(len - 1) % 2 != 0){
        return a | b;
    }else{
        return a ^ b;
    }
    
}
void build(int node, int st, int end) {
    if (st == end) {
        segTree[node] = arr[st];  
        return;
    }
    int mid = (st + end) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, end);
    segTree[node] = merge(segTree[2 * node] , segTree[2 * node + 1], st, end);

}

void update(int node, int st, int end, int pos, int val) {
    if (st == end) {
        arr[pos] = val;
        segTree[node] = val;
        return;
    }
    int mid = (st + end) / 2;
    if (pos <= mid)
        update(2 * node, st, mid, pos, val);
    else
        update(2 * node + 1, mid + 1, end, pos, val);
    segTree[node] = merge(segTree[2 * node] , segTree[2 * node + 1], st , end);

}

// int query(int node, int st, int end, int l, int r) {
//     if (r < st || end < l)
//         return 0; 
//     if (l <= st && end <= r)
//         return segTree[node]; 

//     int mid = (st + end) / 2;
//     int left = query(2 * node, st, mid, l, r);
//     int right = query(2 * node + 1, mid + 1, end, l, r);
//     return left + right;
// }

void solve() {
    int n, q;
    cin >> n;
    cin >> q;
    
    n = 1<<n;
    arr.resize(n);
    segTree.resize(4 * n);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    build(1, 0, n - 1);
    debug(segTree);
debug(q);
    while (q--) {
            int l, r;
            cin >> l >> r;
            update(1, 0, n-1, l-1, r);
            cout << segTree[1] << "\n";
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