#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

#define rep(i,a,b) for(int i=a; i<b; ++i)
#define per(i,a,b) for(int i=a; i>b; --i)
#define each(x,a) for(auto &x : a)

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

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

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
        long long n;
		cin >> n;
		vector<int> vals;
		int pos2 = -1;
		while (n > 0) {
			vals.push_back(n % 3);
			if (vals.back() == 2) pos2 = int(vals.size()) - 1;
			n /= 3;
		}
		vals.push_back(0);
		if (pos2 != -1) {
			int pos0 = find(vals.begin() + pos2, vals.end(), 0) - vals.begin();
			vals[pos0] = 1;
			for (int i = pos0 - 1; i >= 0; --i) {
				vals[i] = 0;
			}
		}
		long long ans = 0;
		long long pw = 1;
		for (int i = 0; i < int(vals.size()); ++i) {
			ans += pw * vals[i];
			pw *= 3;
		}
		cout << ans << endl;
}

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}