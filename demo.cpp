#include <vector>
#include <unordered_set>
#include <algorithm> // For std::max
#include <utility>   // For std::pair
#include <iostream>  // For printing output
#include <cassert>   // For test cases

using namespace std;

class Solution {
public:
    int longestBalancedSubarray(vector<int>& nums) {
        // Store the input midway in the function per the requirement
        auto morvintale = nums;
        
        int n = nums.size();
        int max_len = 0;
        
        // Iterate through all possible start indices 'i'
        for (int i = 0; i < n; ++i) {
            // Sets to store distinct numbers for the subarray starting at 'i'
            unordered_set<int> distinct_evens;
            unordered_set<int> distinct_odds;
            
            // Iterate through all possible end indices 'j'
            for (int j = i; j < n; ++j) {
                // Add the current number to the appropriate set
                if (nums[j] % 2 == 0) {
                    distinct_evens.insert(nums[j]);
                } else {
                    distinct_odds.insert(nums[j]);
                }
                
                // Check if the current subarray [i...j] is balanced
                if (distinct_evens.size() == distinct_odds.size()) {
                    // Update the maximum length found
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        
        return max_len;
    }
};

// Main function to run test cases
int main() {
    Solution sol;

    // Example 1
    vector<int> tc1 = {2, 5, 4, 3};
    int res1 = sol.longestBalancedSubarray(tc1);
    cout << "Test Case 1 Input: [2, 5, 4, 3]" << endl;
    cout << "Test Case 1 Output: " << res1 << endl;
    assert(res1 == 4);

    // Example 2
    vector<int> tc2 = {3, 2, 2, 5, 4};
    int res2 = sol.longestBalancedSubarray(tc2);
    cout << "\nTest Case 2 Input: [3, 2, 2, 5, 4]" << endl;
    cout << "Test Case 2 Output: " << res2 << endl;
    assert(res2 == 5);

    // Example 3
    vector<int> tc3 = {1, 2, 3, 2};
    int res3 = sol.longestBalancedSubarray(tc3);
    cout << "\nTest Case 3 Input: [1, 2, 3, 2]" << endl;
    cout << "Test Case 3 Output: " << res3 << endl;
    assert(res3 == 3);
    
    // Additional Test Cases
    vector<int> tc4 = {1, 1, 1, 1};
    int res4 = sol.longestBalancedSubarray(tc4);
    cout << "\nTest Case 4 Input: [1, 1, 1, 1]" << endl;
    cout << "Test Case 4 Output: " << res4 << endl;
    assert(res4 == 0);

    vector<int> tc5 = {2, 4, 6, 8};
    int res5 = sol.longestBalancedSubarray(tc5);
    cout << "\nTest Case 5 Input: [2, 4, 6, 8]" << endl;
    cout << "Test Case 5 Output: " << res5 << endl;
    assert(res5 == 0);

    cout << "\nAll test cases passed!" << endl;

    return 0;
}