#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int k=3;
        for(int i=0;i<n;i++){
            if(i==0){
                v[i]=1;
            }
            else if(i==n-1){
                v[i]=2;
            }
            else{
                v[i]=k;
                k++;
            }
        }
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;

    }
    return 0;
}
