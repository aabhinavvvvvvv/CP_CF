#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double lld;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 30; i >= 0; i--) {
      ll notSet = 0;
      for (auto num : arr) {
        if (((num >> i) & 1) == 0) {
          notSet++;
        }
      }
      if (notSet <= k) {
        for (auto &num : arr) {
          if (((num >> i) & 1) == 0)
            num |= (1LL << i);
        }
        k -= notSet;
      }
    }

    ll finalAns = arr[0];
    for (auto i : arr) finalAns &= i;
    cout << finalAns << '\n';
  }
  return 0;
}
