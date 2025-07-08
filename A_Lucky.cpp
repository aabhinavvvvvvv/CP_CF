#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int ans=0;
        for(int i=0;i<6;i++){
            if(i<3){
                ans+=s[i];
            }
            else{
                ans-=s[i];
            }
        }
        if(ans){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
 return 0;
}