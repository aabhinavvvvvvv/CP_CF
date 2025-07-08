#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(auto&x:v){
            cin>>x;
        }
        set<int> curr,total;
        curr.insert(v[0]);
        int ans=1;
        for(int i=1;i<n;i++){
            total.insert(v[i]);
            if(curr.count(v[i])){
                curr.erase(v[i]);
            }
            if(curr.empty()){
                ans++;
                curr=total;
            }
        }
        cout<<ans<<endl;
    }
 return 0;
}