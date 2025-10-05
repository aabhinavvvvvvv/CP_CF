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

void solve() {
    int n, k;
    cin >> n >> k;
    int total = n * n;

    if (k == total - 1) {
        cout << "NO\n";
        return;
    }
    int trap = total - k;
    cout << "YES\n";
    vector<string> grid(n, string(n, 'U'));
    if (trap == 0) {
        for (int i = 0; i < n; ++i)
            cout << grid[i] << "\n";
        return;
    }

    vector<pair<int, int>> tc;
    for (int i = n - 1; i >= 0 && tc.size() < trap; i--) {
        for (int j = n - 1; j >= 0 && tc.size() < trap; j--) {
            tc.pb({i, j});
        }
    }

    if (trap >= 2) {
        auto p1 = tc[0];
        auto p2 = tc[1];
        if (p1.first == p2.first) { 
            grid[p1.first][p1.second] = 'L';
            grid[p2.first][p2.second] = 'R';
        } else { 
            grid[p1.first][p1.second] = 'U';
            grid[p2.first][p2.second] = 'D';
        }
    }

    for (int i = 2; i < tc.size(); ++i) {
        auto curr = tc[i];
        auto next = tc[i - 1];
        if (curr.first == next.first) {
            grid[curr.first][curr.second] = (curr.second < next.second) ? 'R' : 'L';
        } else { 
            grid[curr.first][curr.second] = (curr.first < next.first) ? 'D' : 'U';
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << grid[i] << "\n";
    }
}

int main() {
    fastIO();
#ifdef LOCAL
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
