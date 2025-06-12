#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> v(n);
        for(auto& x:v){
            cin>>x;
        }
        int ans=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(v[i-1]<2*v[i]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>k){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
 return 0;
}