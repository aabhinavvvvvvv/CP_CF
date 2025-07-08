#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define ll long long
int main() {
    // Start measuring time
    // auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        // cout << solve(a, b) << endl;
        ll ans = INT_MAX;
        for(ll add=0;add<30;add++){
            ll op=add;
            ll new_b = b + add;
            if(new_b==1) continue;
            ll temp = a;
            while(temp>0){
                temp/=new_b;
                op++;
            }
            ans = min(ans, op);
        }
        cout<<ans<<endl;
    }


    // // End measuring time
    // auto end = high_resolution_clock::now();
    // duration<double> total_time = end - start;
    // cout << fixed << setprecision(6);
    // cerr << "Time taken: " << total_time.count() << " seconds" << endl;

    return 0;
}
