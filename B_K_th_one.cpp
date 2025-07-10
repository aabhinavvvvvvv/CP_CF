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

vector<ll> Tree, v;

void buildTree(int node, int st, int end) {
    if (st == end) {
        Tree[node] = v[st];
        return;
    }
    int mid = (st + end) / 2;
    buildTree(2 * node, st, mid);
    buildTree(2 * node + 1, mid + 1, end);
    Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
}

void updateTree(int node, int st, int end, int idx) {
    if (st == end) {
        v[idx] = (v[idx] == 0 ? 1 : 0);
        Tree[node] = v[idx];
        return;
    }
    int mid = (st + end) / 2;
    if (idx <= mid)
        updateTree(2 * node, st, mid, idx);
    else
        updateTree(2 * node + 1, mid + 1, end, idx);
    Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
}

ll queryTree(int node, int st, int end, int k) {
    if(st == end){
        return st;
    }
    int mid = st + (end - st)/2;
    if(Tree[2*node] > k){
        return queryTree(2*node, st, mid, k);
    }
    else{
        return queryTree(2*node + 1, mid+1 , end, k - Tree[2*node]);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    v.resize(n);
    Tree.assign(4 * n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];

    buildTree(1, 0, n - 1);

    while (m--) {
        int  x, y;
        cin >> x >> y;
        if (x == 1) {
            updateTree(1, 0, n - 1, y);
        } else if (x == 2) {
            cout << queryTree(1, 0, n - 1, y) << "\n";
        }
    }
}

int main() {
    fastIO();
    solve();
    return 0;
}
