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
const int N_MAX = 2e5 + 5;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rbegin()
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
    int n;
    ll c;
    int d;
    cin >> n >> c >> d;

    vll a_rewards(n);
    for (int i = 0; i < n; ++i) {
        cin >> a_rewards[i];
    }

    sort(a_rewards.rbegin(), a_rewards.rend());

    vector<ll> pref_sum_a(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref_sum_a[i+1] = pref_sum_a[i] + a_rewards[i];
    }

    auto calculate_total_coins = [&](ll k_val) {

        ll count_in_cycle = min((ll)n, k_val + 1);

        ll sum_of_cycle_quests = pref_sum_a[count_in_cycle];

        ll num_full_cycles = d / (k_val + 1);

        ll remaining_days = d % (k_val + 1);

        ll total_coins = num_full_cycles * sum_of_cycle_quests;
        if (remaining_days > 0) {
            total_coins += pref_sum_a[min((ll)n, remaining_days)];
        }
        return total_coins;
    };

    if (calculate_total_coins(0) < c) {
        cout << "Impossible\n";
        return;
    }

    if (pref_sum_a[min((ll)n, (ll)d)] >= c) {
        cout << "Infinity\n";
        return;
    }

    ll low = 0, high = 200000 + 7;
    ll ans_k = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (calculate_total_coins(mid) >= c) {
            ans_k = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans_k << "\n";
}

int main() {
    fastIO();

#ifdef LOCAL
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
