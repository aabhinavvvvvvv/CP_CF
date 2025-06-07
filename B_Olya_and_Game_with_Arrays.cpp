#include <bits/stdc++.h>
using namespace std;
# define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<ll>> arr(n);
        for (ll i = 0; i < n; i++)
        {
            ll temp;
            cin >> temp;
            arr[i].resize(temp);
            for (ll j = 0; j < temp; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (ll i = 0; i < n; i++)
            sort(arr[i].begin(), arr[i].end());
        
        long long lsm=INT_MAX;
        long long lfm=INT_MAX;
        long long sum=0;
        for(auto x:arr){
            sum += x[1];
            lsm=min(lsm,x[1]);
            lfm=min(lfm,x[0]);
        }
        sum+=lfm-lsm;
        cout<<sum<<endl;
    }
    return 0;
}