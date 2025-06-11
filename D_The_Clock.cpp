#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string time) {
    return time[0] == time[4] && time[1] == time[3];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int x;
        cin >> s >> x;

        int H = stoi(s.substr(0, 2));
        int M = stoi(s.substr(3, 2));

        int seen[1440] = {};  
        int count = 0;

        while (!seen[H * 60 + M]) {
            seen[H * 60 + M] = 1;

            stringstream ss;
            ss << setw(2) << setfill('0') << H << ":"
               << setw(2) << setfill('0') << M;
            if (isPalindrome(ss.str()))
                count++;

            int total = H * 60 + M + x;
            total %= 1440;
            H = total / 60;
            M = total % 60;
        }

        cout << count << endl;
    }
    return 0;
}
