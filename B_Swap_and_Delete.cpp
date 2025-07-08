#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int count0=0;
        int count1=0;
        for(int i=0;i<s.size();i++){
            if((s[i]-'0')==0)
                count0++;
            else
                count1++;
        }
        int cost=0;
        if(count0==count1){
            cout<<cost<<endl;
            continue;;
        }
        for(int i=0;i<s.size();i++){
            if(s[i - cost]-'0' == 0){
                if(count1 > 0) count1--;
                else cost++;
            }
            else {
                if(count0 > 0) count0--;
                else cost++;
            }
        }
        cout<<cost<<endl;
    }
 return 0;
}