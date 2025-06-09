#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n);
        for(auto&x:v){
            cin>>x;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[j]<=v[i])
                    ans++;
            }
        }
        cout<<ans<<endl;

    }
 return 0;
}