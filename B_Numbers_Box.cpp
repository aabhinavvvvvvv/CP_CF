#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m));
        int mini=INT_MAX;
        int nega=0;
        int sum=0;
        int actualSum=0;
        int zero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
                sum+=abs(grid[i][j]);
                // actualSum+=grid[i][j];
                if(grid[i][j]<0){
                    nega++;
                }
                else if(grid[i][j]==0){
                    zero++;
                }
                mini=min(abs(grid[i][j]),mini);
            }
        }
        if(nega&1){
            if(zero==0){
                cout<<sum-2*mini<<endl;
                continue;
            }
        }
        cout<<sum<<endl;

    }
 return 0;
}