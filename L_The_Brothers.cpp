/**********************************************************
 *  Competitive Programming Template by Abhinav Gupta     *
 *  B.Tech CSE @ MNIT Jaipur | Code Enthusiast            *
 *  Fast I/O, Debug Macros, Common Aliases & Utilities    *
 *                                                        *
 *  ⚡ Good Luck, Have Fun & Keep Grinding! ⚡             *
 **********************************************************/

#include <bits/stdc++.h>
using namespace std;

// Typedefs for convenience
#define ll long long
#define ull unsigned long long
#define ld long double

// Vectors and Pairs
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>

// Common STL shortcuts
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

// Loop macros
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define per(i,a,b) for(int i=a; i>b; --i)
#define each(x,a) for(auto &x : a)

// Constants
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

// Debugging utilities
#ifdef LOCAL
#define debug(x) cerr << #x << " = "; _print(x); cerr << '\n';
#else
#define debug(x)
#endif

void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(string x) { cerr << '"' << x << '"'; }
void _print(char x) { cerr << '\'' << x << '\''; }
template<class T> void _print(vector<T> v) { cerr << '['; for(auto x : v) { _print(x); cerr << ' '; } cerr << ']'; }

// Fast IO
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Problem-specific logic
void solve() {
    string f1, s1; cin >> f1 >> s1;
    string f2, s2; cin >> f2 >> s2;
    
    if (s1 == s2)
        cout << "ARE Brothers\n";
    else
        cout << "NOT\n";
}

// Main driver
int main() {
    fastIO();
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases
    while (t--) solve();
    return 0;
}

/**********************************************************
 * Notes:
 * - Use `debug(var)` to print during local testing
 * - Avoid STL overuse in tight constraints
 * - Always validate inputs & edge cases
 * - This template is for personal use, adapt as needed
 **********************************************************/
