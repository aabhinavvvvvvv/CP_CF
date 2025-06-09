#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;cin>>t;
    while(t--){
        long long n,k,b,s;cin>>n>>k>>b>>s;
        long long mini=k*b;
        long long maxi=k*b + (k-1)*n;
        if(s<mini || s>maxi){
            cout<<-1<<endl;
        }
        else{
            vector<long long> ans(n,0);
            ans[0]=mini;
            s-=mini;
            for(long long i=0;i<n;i++){
                if(s<0) break;
                else{
                    long long add=min(k-1,s);
                    ans[i]+=add;
                    s-=add;
                }
            }
            for(auto x:ans){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
 return 0;
}