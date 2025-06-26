#include <bits/stdc++.h>
using namespace std;

/*
 * Author: Abhinav Gupta
 * GitHub: @aabhinavvvvvvv
 * MAHAKAL KI JAI
 */

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

vector<ll> getdiv(ll n) {
    vector<ll> divisors;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) divisors.push_back(n / i);
        }
    }
    return divisors;
}

int main() {
    fastIO();

    int T;
    cin >> T;
    while (T--) {
        ll X, Y, Z, C;
        cin >> X >> Y >> Z >> C;

        if (X == Y) {
            cout << 0 << "\n";
            continue;
        }

        ll ans = LLONG_MAX;
        if(X<Y)swap(X,Y);
        {
            ll gx = gcd(X, Z), ly = lcm(Y, Z);
            if (gx == ly) {
                ans = min(ans, C);
            } else {
                ll l1 = lcm(gx, Z), g1 = gcd(ly, Z);
                if (l1 == g1) {
                    ans = min(ans, 2 * C);
                }
            }
        }

        vector<ll> dx = getdiv(X);
        for (ll d : dx) {
            ll val = abs(Z - d) + C;
            ll gx = gcd(X, d), ly = lcm(Y, d);
            if (gx == ly) {
                ans = min(ans, val);
            }
        }
    

        vector<ll> dy = getdiv(Y);
        for (ll d : dy) {
            ll val = abs(Z - d) + C;
            ll lx = lcm(X, d), gy = gcd(Y, d);
            if (lx == gy) {
                ans = min(ans, val);
            }
        }

        // if (ans == LLONG_MAX) {
            // cout << -1 << endl;  
        // } else {
            cout << ans << endl;
        // }
    }

    return 0;
}
