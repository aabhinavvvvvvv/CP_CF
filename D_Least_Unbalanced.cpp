#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;

    int len = 1 << N;   
    ll base = K / len;  
    int rem = K % len;  

    vector<ll> ans(len, base);

    if (rem == 0) {
        cout << 0 << "\n";
        for (ll x : ans) cout << x << " ";
        cout << "\n";
        return 0;
    }

    cout << 1 << "\n"; 
    
    for (int i = 0; i < rem; i++) {
        ans[(2 * i) % len]++;  
    }

    for (ll x : ans) cout << x << " ";
    cout << "\n";
}
