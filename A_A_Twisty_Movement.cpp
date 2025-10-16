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
    int n; cin >> n;
    vi v(n);
    rep(i, 0, n){
        cin >> v[i];
    }
    vi ones(n + 1, 0), twos(n + 1, 0);
    rep(i, 0, n){
        ones[i + 1] = ones[i] + (v[i] == 1);
        twos[i + 1] = twos[i] + (v[i] == 2);
    }
    int ans = 0;
    for(int l = 0; l < n; l++){
        int lnds = 0;
        for(int r = l; r < n; r++){
            int midtwo = twos[r + 1] - twos[l];
            lnds = max(lnds + (v[r] == 1), midtwo);
            int preone = ones[l];
            int suftwo = twos[n] - twos[r + 1];
            ans = max(ans, preone + lnds + suftwo);
        }
    }
    cout << ans << endl;
}

void solve2(){
    int n; cin >> n;
    vi v(n);
    rep(i, 0, n){
        cin >> v[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        // calculates max no of ones in [0, i] we can get
        int sum = 0;
        int ones = 0;
        for(int j = 0; j < i; j++){
            sum += v[j] == 1;
        }
        ones = max(ones, sum);
        for(int j = 0; j < i; j++){
            if(v[j] == 1) sum--;
            else sum++;
            ones = max(ones, sum);
        }
        // calculates max no of twos in [i + 1, n] we can get
        sum = 0;
        int twos = 0;
        for(int j = i; j < n; j++){
            sum += v[j] == 2;
        }
        twos = max(twos, sum);
        for(int j = i; j < n; j++){
            if(v[j] == 2) sum--;
            else sum++;
            twos = max(twos, sum);
        }
        ans = max(ans, ones + twos);
    }
    cout << ans << endl;
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
    // cin >> t;
    while (t--) solve();

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;

    return 0;
}