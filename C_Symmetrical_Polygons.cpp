#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

template <typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using oms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// read question properly
// don't forget newlines!!!!!!
// take care about cin >> t;
// comment the optimization before debugging
// ALWAYS USE FIXED << SETPRECISION WHILE OUTPUTTING FLOATS

void solve()
{
    //at least 2 should be equal in the array
    //take all the pairs, then find two nums
    //such that a - b < sum of all pairs, and a + b is maximised
    //(b can be zero as well)
    ll n;
    cin >> n;
    ia(a,n);
    ll ans = 0;
    map<ll,ll> fr;
    f(i,n) {
        fr[a[i]]++;
    }
    vector<ll> v;
    ll cnt = 0;
    for(auto x : fr) {
        if(x.second & 1)
        v.push_back(x.first);
        ans += (x.second / 2) * 2 * x.first;
        cnt += x.second / 2 * 2;
    }

    if(ans == 0) {
        cout << 0 << nline;
        return;
    }

    sort(v.begin(), v.end());

    ll finans = 0;

    f(i,v.size()) {
        if(v[i] < ans) {
            finans = max(finans, ans + v[i]);
        }
    }

    for(int i = 1; i < v.size(); i++) {
        if(v[i] - v[i-1] < ans) {
            finans = max(finans, ans + v[i] + v[i-1]);
        }
    }

    if(cnt >= 4) {
        finans = max(finans, ans);
    }

    cout << finans << nline;
}

int main()
{
#ifdef PRADY
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t T = clock();
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

#ifdef PRADY
    cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
#endif
    return 0;
}