#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;cin>>n;
    string s;cin>>s;
    stack<char> st;
    int op=0;
    for(auto x:s){
        if(x=='('){
            st.push(x);
        }
        else if(x==')'){
            if(!st.empty()){
                st.pop();
            }
            else{
                op++;
            }
        }
    }
    int ans=(op+st.size())/2;
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