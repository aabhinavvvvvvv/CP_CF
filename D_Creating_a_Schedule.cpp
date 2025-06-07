#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while (t--)
    {
        int n,m;cin>>n>>m;
        vector<int> arr(m);
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<6;j++){
                if((i+j)&1){
                    cout<<arr[i/2]<<" ";
                }
                else{
                    cout<<arr[m-1-i/2]<<" ";
                }
            }
            cout<<endl;
        }
    }
    
 return 0;
}