#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> good;  
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i]<i){
            good.push_back(i);
        }
    }

    long long ans = 0;
    for (int j = 1; j <= n; j++) {
        if (a[j] < j) {
            int cnt = lower_bound(good.begin(), good.end(), a[j]) - good.begin();
            ans += cnt;
        }
    }

    cout << ans << '\n';
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
}
