#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define el cout << '\n'

int fib[12]; 
void init() {
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i < 12; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void ItsJustTimeToGM() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        vector<long long> d(3);
        cin >> d[0] >> d[1] >> d[2];
        sort(all(d));
        if (d[0] >= fib[n] && d[2] >= fib[n + 1]) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TC = 1;
    init();
    cin >> TC;
    while (TC--) ItsJustTimeToGM();
}
