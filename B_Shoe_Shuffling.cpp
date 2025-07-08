#define ll long long 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(auto&x:arr){

            cin>>x;
        
        }
        vector<int> ans(n);
        bool possible=true;
        for(int i=0;i<n;){
            int cnt=0;
            int j=i;
            while( j<n-1 && arr[j]==arr[j+1]){
                ans[j+1]=j+1;
                cnt++;
                j++;
            }
            ans[i]=j+1;
            i=j+1;
            if(cnt==0){
                possible=false;
                break;
            }
        }
        if(!possible){
            cout<<-1<<endl;
        }
        else{
            for(auto x:ans){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
        
 return 0;
}