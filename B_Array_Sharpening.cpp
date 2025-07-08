#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<int> left(n),right(n);
        for(int i=0;i<n;i++){
            if(a[i]>=i){
                left[i]=1;
            }
            else{
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(a[i]>=n-i-1){
                right[i]=1;
            }
            else{
                break;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(left[i] && right[i]){
                ans=1;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }

    return 0;
}
