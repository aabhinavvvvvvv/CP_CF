#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        unordered_map<int,int> mp;
        for(auto&x :v){
            cin>>x;
            mp[x]++;
        }
        int ans=0;
        for(auto x:mp){
            ans=max(ans,x.second);
        }
        cout<<ans<<endl;
    }
 return 0;
}