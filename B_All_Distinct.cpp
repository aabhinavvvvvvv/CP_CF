#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<int, int> freq;
        for(int i = 0; i < n; ++i) {
            int x; cin >> x;
            freq[x]++;
        }
        int unique_count = freq.size();
        int duplicates = n - unique_count;
        if (duplicates % 2 == 0) {
            cout << unique_count << endl;
        } else {
            cout << unique_count - 1 << endl;
        }
    }
    return 0;
}
