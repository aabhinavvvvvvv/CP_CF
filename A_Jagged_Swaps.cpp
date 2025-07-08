#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int element;
        vector<int>ans;

        for(int i=0;i<n;i++)

        {

            cin>>element;

           ans.push_back(element);

        }

        if(ans[0]==1)cout<<"YES"<<endl;

        else cout<<"NO"<<endl;



    }
 return 0;
}