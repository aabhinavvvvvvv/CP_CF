#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define vec vector
#define pb push_back
#define all(x) x.begin(), x.end()

const int N = 1e5 + 5;
vec<int> spf(N);

void precompute() {
    iota(all(spf), 0);
    for (int i = 2; i * i <= N; ++i)
        if (spf[i] == i)
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

void solve() {
    int n;
    cin >> n;

    vec<int> p(n + 1, 0), used(n + 1, 0);
    vec<int> primes;

    for (int i = 2; i <= n; ++i)
        if (spf[i] == i)
            primes.pb(i);

    reverse(all(primes)); // process large primes first (to avoid trivial small cycles)

    for (int pr : primes) {
        vec<int> bucket;
        for (int m = pr; m <= n; m += pr)
            if (!used[m])
                bucket.pb(m);

        if (bucket.size() > 1) {
            for (size_t k = 0; k < bucket.size(); ++k) {
                int u = bucket[k];
                int v = bucket[(k + 1) % bucket.size()];
                p[u] = v;
                used[u] = 1;
            }
        }
    }

    // assign self to remaining unassigned (fixed points)
    for (int i = 1; i <= n; ++i)
        if (!p[i])
            p[i] = i;

    for (int i = 1; i <= n; ++i)
        cout << p[i] << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
