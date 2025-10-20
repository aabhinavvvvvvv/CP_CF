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


int spf[N]; // Assumes N is defined in the template (e.g., const int N = 2e5 + 5);

void buildSPF() {
    for(int i=1;i<N;i++) spf[i] = i;
    for(int i=2;i*i<N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<N;j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
    // Call buildSPF() once in main() before test cases
}

vi factorize(int x){
    vi factors;
    while(x>1){
        factors.pb(spf[x]);
        x /= spf[x];
    }
    return factors;
}
void solve() {
    int n; 
    cin >> n;
    vi a(n), b(n);
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> b[i];

    // check for ans = 0
    map<int,int> mp;
    rep(i,0,n){
        set<int> st;
        ll x = a[i];
        while(x > 1){
            st.insert(spf[x]);
            x /= spf[x];
        }
        for(auto x : st) mp[x]++;
    }
    for(auto x : mp){
        if(x.second >= 2){
            cout << 0 << endl;
            return;
        }
    }

    // check for ans = 1
    rep(i,0,n){
        ll x = a[i]+1;
        set<int> st;
        while(x > 1){
            st.insert(spf[x]);
            x /= spf[x];
        }
        for(auto x : st){
            if(mp[x]){
                cout << 1 << endl;
                return;
            }
        }
    }

    cout << 2 << endl;
}




int main() {
    fastIO();
#ifdef LOCAL
    // freopen("Error.txt", "w", stderr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    auto begin = chrono::high_resolution_clock::now();

    // sieve(1e6);
    buildSPF();

    int t = 1;
    cin >> t;
    while (t--) solve();

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;

    return 0;
}

