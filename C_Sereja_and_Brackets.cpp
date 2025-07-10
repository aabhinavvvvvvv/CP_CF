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
struct state{
    int lefto = 0  , rightc = 0 , maxlen = 0;
    state() : lefto(0), rightc(0), maxlen(0) {};

    state(char c){
        lefto = 0;
        rightc = 0;
        maxlen = 0;
        if(c == '('){
            lefto = 1 ;
        }
        else if(c == ')'){
            rightc = 1;
        }
    }
};
vector<state> segTree;
string s; 
state merge(state a, state b){
    state temp;
    int matched = min(a.lefto, b.rightc);
    temp.maxlen = a.maxlen + b.maxlen + 2 * matched;
    temp.lefto = a.lefto + b.lefto - matched; 
    temp.rightc = a.rightc + b.rightc - matched;
    return temp;
}
void build(int node, int st, int end) {
    if (st == end) {
        segTree[node] = state(s[st]);
        return;
    }
    int mid = (st + end) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, end);
    segTree[node] = merge(segTree[2 * node] , segTree[2 * node + 1]);
}

// void update(int node, int st, int end, int pos, int val) {
//     if (st == end) {
//         arr[pos] = val;
//         segTree[node] = val;
//         return;
//     }
//     int mid = (st + end) / 2;
//     if (pos <= mid)
//         update(2 * node, st, mid, pos, val);
//     else
//         update(2 * node + 1, mid + 1, end, pos, val);
//     segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
// }

state query(int node, int st, int end, int l, int r) {
    if (r < st || end < l)
        return state(); 
    if (l <= st && end <= r)
        return segTree[node]; 

    int mid = (st + end) / 2;
    state left = query(2 * node, st, mid, l, r);
    state right = query(2 * node + 1, mid + 1, end, l, r);
    return merge(left , right);
}

void solve() {
    cin >> s;
    int q; cin >> q;
    int n = s.size();
    segTree.resize(4 * n);
    build(1, 0, n - 1);

    while (q--) {
            int l, r;
            cin >> l >> r;
            cout << query(1 , 0 , n-1 , l-1 , r-1).maxlen << "\n";
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