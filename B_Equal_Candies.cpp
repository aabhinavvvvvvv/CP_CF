#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        int mini=INT_MAX;
        for(auto& x:v){
            cin>>x;
            mini=min(mini,x);
        }
        int ans=0;
        for(auto x:v){
            ans+=x-mini;
        }
        cout<<ans<<endl;

    }
 return 0;
}