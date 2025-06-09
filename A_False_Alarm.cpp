#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int x;cin>>x;
        vector<int> v(n);
        int first1=-1;
        int last1=-1;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]==1 && first1==-1){
                first1=i;
            }
            if(v[i]==1){
                last1=i;
            }
        }

        if(last1-first1+1 > x){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
 return 0;
}