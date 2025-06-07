#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        int cnt = 0;
        while (x > 0) {
            x >>= 1; 
            cnt++;
        }
        cout << (cnt * 2 + 1) << endl;
    }
    return 0;
}
