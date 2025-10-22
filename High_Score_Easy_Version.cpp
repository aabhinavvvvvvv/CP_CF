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
using pil = pair<ll, int>; // Pair: <long long, int> for (value, count)

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
#define fastIO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

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

struct comp {
    bool operator()(const pil &a, const pil &b) const {
        return a.first < b.first; 
    }
};

// Helper function to greedily pair two simple heaps
ll pair_heaps(priority_queue<pil, vector<pil>, comp>& pqa, 
              priority_queue<pil, vector<pil>, comp>& pqb) {
    ll score = 0;
    while (!pqa.empty() && !pqb.empty()) {
        auto [va, ca] = pqa.top(); pqa.pop();
        auto [vb, cb] = pqb.top(); pqb.pop();
        int used = min(ca, cb);
        score += 1LL * (va + vb) * used;
        ca -= used;
        cb -= used;
        if (ca > 0) pqa.push({va, ca});
        if (cb > 0) pqb.push({vb, cb});
    }
    return score;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vll a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    map<ll, int> mpa, mpb;
    for (ll x : a) mpa[x]++;
    for (ll x : b) mpb[x]++;

    priority_queue<pil, vector<pil>, comp> pqa_rem, pqb_rem, pqa_com, pqb_com;
    
    set<ll> all_keys;
    for(auto const& [key, val] : mpa) all_keys.insert(key);
    for(auto const& [key, val] : mpb) all_keys.insert(key);

    for(ll x : all_keys) {
        int ca = mpa[x];
        int cb = mpb[x];
        int common = min(ca, cb);
        if(common > 0) {
            pqa_com.push({x, common});
            pqb_com.push({x, common});
        }
        if(ca - common > 0) {
            pqa_rem.push({x, ca - common});
        }
        if(cb - common > 0) {
            pqb_rem.push({x, cb - common});
        }
    }

    ll ans = 0;
    ans += pair_heaps(pqa_rem, pqb_rem);

    ans += pair_heaps(pqa_rem, pqb_com);
    ans += pair_heaps(pqa_com, pqb_rem);

    while(!pqa_rem.empty()) {
        pqa_com.push(pqa_rem.top()); pqa_rem.pop();
    }
    while(!pqb_rem.empty()) {
        pqb_com.push(pqb_rem.top()); pqb_rem.pop();
    }

    while (!pqa_com.empty() && !pqb_com.empty()) {
        auto [va, ca] = pqa_com.top(); pqa_com.pop();
        auto [vb, cb] = pqb_com.top(); pqb_com.pop();

        if (va == vb) {
            if (pqa_com.empty() && pqb_com.empty()) break; 

            ll va2 = 0;
            if (!pqa_com.empty()) va2 = pqa_com.top().first;
            ll vb2 = 0;
            if (!pqb_com.empty()) vb2 = pqb_com.top().first;
            
            if (va2 == 0 && vb2 == 0) break;

            if (va2 > vb2) {
                auto [va2_val, ca2] = pqa_com.top(); pqa_com.pop();
                int used = min(ca2, cb);
                ans += 1LL * (va2_val + vb) * used;
                ca2 -= used;
                cb -= used;
                if (ca2 > 0) pqa_com.push({va2_val, ca2});
                if (cb > 0) pqb_com.push({vb, cb});
                pqa_com.push({va, ca});
            } else {
                auto [vb2_val, cb2] = pqb_com.top(); pqb_com.pop();
                int used = min(ca, cb2);
                ans += 1LL * (va + vb2_val) * used;
                ca -= used;
                cb2 -= used;
                if (ca > 0) pqa_com.push({va, ca});
                if (cb2 > 0) pqb_com.push({vb2_val, cb2});
                pqb_com.push({vb, cb});
            }
        } else {
            int used = min(ca, cb);
            ans += 1LL * (va + vb) * used;
            ca -= used; cb -= used;
            if (ca > 0) pqa_com.push({va, ca});
            if (cb > 0) pqb_com.push({vb, cb});
        }
    }

    cout << ans << "\n";
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
    cin >> t;
    while (t--) solve();

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;

    return 0;
}