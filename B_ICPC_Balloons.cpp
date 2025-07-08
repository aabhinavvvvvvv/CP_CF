#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;cin>>n;
    string s;cin>>s;
    set<char> st;
    int ans=0;
    for(auto x:s){
        if(st.count(x)==0){
            ans++;
            st.insert(x);
        }
        ans++;
    }
    cout<<ans<<endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}