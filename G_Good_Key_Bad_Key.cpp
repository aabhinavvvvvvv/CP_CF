#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    long long val=0;
    long long ans=0;
    for(int i=-1;i<n;i++){
        if(i!=-1) val+=a[i]-k;
        long long now=val;
        for(int j=i+1;j<min(n,i+32);j++){
            int curr=a[j];
            curr>>=j-i;
            now+=curr;
        }
        ans=max(ans,now);
    }
    cout<<ans<<endl;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
