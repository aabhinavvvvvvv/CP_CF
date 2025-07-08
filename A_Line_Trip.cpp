#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int x;cin>>x;
        vector<int> gas(n);
        for(int i=0;i<n;i++){
            cin>>gas[i];
        }
        int initial=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            int dist = gas[i] - initial;
            initial = gas[i];
            maxi = max(maxi,dist);
        }
        maxi = max(maxi,2*(x-initial));
        cout<<maxi<<endl;
    }
 return 0;
}