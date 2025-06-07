#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int atob=0;
        int btoa=0;
        int atoc=0;
        int ctoa=0;
        int btoc=0;
        int ctob=0;
        int convertToA=0;
        int convertToB=0;
        int convertToC=0;
        unordered_map<string,int> mp;
        vector<string> queries;
        for (int i = 0; i < q; i++) {
            char c1, c2;
            cin >> c1 >> c2;
            string key = string(1, c1) + "to" + string(1, c2);
            queries.push_back(key);
            if(key=="btoa") convertToA++;
            if(key=="ctoa") convertToA++;
            if(key=="atob") convertToB++;
            if(key=="ctob") convertToB++;
            if(key=="atoc") convertToC++;
            if(key=="btoc") convertToC++;
        }
        for(auto x:queries){
            if(x=="btoa"){
                s[convertToA - 1]="a";
                convertToA--;
            }
            if(x=="ctoa"){
                if("btoc")
            }
        }


        cout << '\n';
    }
    return 0;
}
