#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        long long p;cin>>p;
        vector<long long> a(n);
        vector<long long> b(n);
        vector<pair<long long,long long>> v(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            v[i]={b[i],a[i]};
        }
        sort(v.begin(),v.end());
        long long cost = p;
        long long shared_people=1;
        for(auto it : v){
            long long sharing_cost = it.first;
            long long can_be_shared = it.second;
            if(sharing_cost >=p){
                break;
            }
            if(can_be_shared + shared_people > n){
                cost += (n-shared_people)*sharing_cost;
                shared_people=n;
                break;
            }
            else{
                cost += can_be_shared*sharing_cost;
                shared_people+=can_be_shared;
            }
        }
        cost += (n-shared_people)*p;
        cout<<cost<<endl;
    }
 return 0;
}