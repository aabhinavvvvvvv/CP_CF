#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int val=sqrt(n);
        if(val==sqrt(n)){
            cout<<0<<" "<<val<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
 return 0;
}