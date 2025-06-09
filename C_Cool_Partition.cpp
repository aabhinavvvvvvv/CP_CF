#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        for(auto&x :v){
            cin>>x;
        }
        set<int> prev,total;
        int ans=0;
        for(auto x:v){
            total.insert(x);
            if(prev.count(x)){
                prev.erase(x);
            }
            if(prev.empty()){
                ans++;
                prev=total;
            }
        }
        cout<<ans<<endl;
    }
 return 0;
}