#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            pq.push({v[i], i});
        }

        vector<int> ans(n);
        int pos = 1;
        long long total = 0; 

        while(!pq.empty()){
            auto ele = pq.top(); pq.pop();
            ans[ele.second] = pos;
            total += 1LL * abs(pos) * v[ele.second]; 

            if(pos > 0) pos = -pos;
            else { pos = -pos; pos++; }
        }

        cout << total * 2LL << endl; 
        cout << 0 << " ";
        for(auto x : ans){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
