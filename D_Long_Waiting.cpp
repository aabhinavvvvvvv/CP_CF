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
using state = pair<long long, int>; 
void solve() {
    int n, k;
    cin >> n >> k;

    vector<long long> A(n), B(n), C(n);
    for(int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i];

    vector<long long> v(n, -1);
    queue<int> q;
    long long cur = 0;
    int next = 0;

    priority_queue<state, vector<state>, greater<state>> pq;

    long long t = 0;
    while(next < n || !q.empty() || !pq.empty()){
        long long nextEvent = LLONG_MAX;
        if(next < n) nextEvent = min(nextEvent, A[next]);
        if(!pq.empty()) nextEvent = min(nextEvent, pq.top().first);

        t = max(t, nextEvent);

        while(!pq.empty() && pq.top().first == t){
            auto p = pq.top(); pq.pop();
            int idx = p.second;
            cur -= C[idx];
        }

        while(next < n && A[next] == t){
            q.push(next);
            next++;
        }

        while(!q.empty()){
            int idx = q.front();
            if(cur + C[idx] <= k){
                q.pop();
                v[idx] = t;
                cur += C[idx];
                pq.push({t + B[idx], idx});
            } else break;
        }
    }

    for(int i = 0; i < n; i++) cout << v[i] << "\n";
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