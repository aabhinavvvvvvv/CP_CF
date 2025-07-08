/*
 * Competitive Programming Template
 * Author: Abhinav Gupta
 * GitHub: @aabhinavvvvvvv
 * MAHAKAL KI JAI
 */

#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

const ll INF = 1e18; // Using template's INF
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

#define debug(x) std::cerr << #x << " = "; _print(x); std::cerr << std::endl;

void _print(int t) { std::cerr << t; }
void _print(long long t) { std::cerr << t; }
void _print(unsigned long long t) { std::cerr << t; }
void _print(std::string t) { std::cerr << '"' << t << '"'; }
void _print(char t) { std::cerr << '\'' << t << '\''; }
void _print(long double t) { std::cerr << t; }
void _print(double t) { std::cerr << t; }

template <typename T, typename V> void _print(std::pair<T, V> p);
template <typename T> void _print(std::vector<T> v);
template <typename T> void _print(std::set<T> v);
template <typename T> void _print(std::multiset<T> v);
template <typename T, typename V> void _print(std::map<T, V> v);

template <typename T, typename V>
void _print(std::pair<T, V> p) { std::cerr << '{'; _print(p.first); std::cerr << ", "; _print(p.second); std::cerr << '}'; }
template <typename T>
void _print(std::vector<T> v) { std::cerr << "[ "; for (T i : v) _print(i), std::cerr << " "; std::cerr << "]"; }
template <typename T>
void _print(std::set<T> v) { std::cerr << "[ "; for (T i : v) _print(i), std::cerr << " "; std::cerr << "]"; }
template <typename T>
void _print(std::multiset<T> v) { std::cerr << "[ "; for (T i : v) _print(i), std::cerr << " "; std::cerr << "]"; }
template <typename T, typename V>
void _print(std::map<T, V> v) { std::cerr << "[ "; for (auto i : v) _print(i), std::cerr << " "; std::cerr << "]"; }

/*
 * Bakchodi Mat Kar Laude
 * Chup Chap code kar
 * I will not be responsible for any damage caused by this code
 */

void solve() {
    ll a, b, x, y;
    std::cin >> a >> b >> x >> y;

    if (a == b) {
        std::cout << 0 << std::endl;
        return;
    }

    const int MAX_NODE_VALUE = 101;
    const int ARRAY_SIZE = MAX_NODE_VALUE + 1;

    std::vector<ll> dist(ARRAY_SIZE, INF);

    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<std::pair<ll, int>>> pq;

    dist[a] = 0;
    pq.push({0, (int)a});

    while (!pq.empty()) {
        ll current_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_cost > dist[u]) {
            continue;
        }
        
        if (u == b) {
            std::cout << current_cost << std::endl;
            return;
        }

        int v1 = u + 1;
        if (v1 <= MAX_NODE_VALUE) { 
            if (dist[u] + x < dist[v1]) {
                dist[v1] = dist[u] + x;
                pq.push({dist[v1], v1});
            }
        }

        int v2 = u ^ 1;
        if (v2 >= 0 && v2 <= MAX_NODE_VALUE) { 
            if (dist[u] + y < dist[v2]) {
                dist[v2] = dist[u] + y;
                pq.push({dist[v2], v2});
            }
        }
    }

    std::cout << -1 << std::endl;
}

int main() {
    fastIO();

    // Always redirect stderr to Error.txt for debug
    freopen("Error.txt", "w", stderr);

#ifdef LOCAL
    // Only redirect input/output during local debugging
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    std::cin >> t;
    while (t--) solve();
    return 0;
}
