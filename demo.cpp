#include <bits/stdc++.h>
using namespace std;

int flipDigits(int x) {
    int res = 0;
    while (x > 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int countSpecialPairs(vector<int>& arr) {
    unordered_map<int, long long> freq;
    
    for (int x : arr) {
        int key = x - flipDigits(x);
        freq[key]++;
    }
    
    long long total = 0;
    for (auto& a : freq) {
        total += a.second * (a.second + 1) / 2; // pairs with i <= j
    }
    
    return total;
}

int main() {
    vector<int> arr1 = {1, 20, 2, 11};
    cout << countSpecialPairs(arr1) << "\n"; // Output: 7

    vector<int> arr2 = {32, 332, 100};
    cout << countSpecialPairs(arr2) << "\n"; // Output: 4

    return 0;
}
