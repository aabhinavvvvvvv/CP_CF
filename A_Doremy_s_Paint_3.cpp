#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        vector<int> nums(n);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()>=3) cout<<"No"<<endl;
        else if(mp.size()==1) cout<<"Yes"<<endl;
        else {
            if (n == 2) {
                cout << "Yes" << endl;
            } else {
                vector<int> freq;
                for (auto p : mp) {
                    freq.push_back(p.second);
                }
                if (freq[0] == freq[1]) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }

    }
    
 return 0;
}