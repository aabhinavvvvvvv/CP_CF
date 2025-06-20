#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_valid(int i, int j) {
    return i >= 0 && i < 7 && j >= 0 && j < 7;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> grid(7);
        for (int i = 0; i < 7; ++i) {
            cin >> grid[i];
        }

        int flips = 0;

        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (grid[i][j] == 'B') {
                    int count = 0;
                    // Check top-left
                    if (is_valid(i-1, j-1) && grid[i-1][j-1] == 'B') count++;
                    // Check top-right
                    if (is_valid(i-1, j+1) && grid[i-1][j+1] == 'B') count++;
                    // Check bottom-left
                    if (is_valid(i+1, j-1) && grid[i+1][j-1] == 'B') count++;
                    // Check bottom-right
                    if (is_valid(i+1, j+1) && grid[i+1][j+1] == 'B') count++;

                    if (count == 4) {
                        // Need to flip this cell or one of its diagonals
                        flips++;
                        // Flip the current cell to resolve all four diagonals at once
                        grid[i][j] = 'W';
                    }
                }
            }
        }

        cout << flips << endl;
    }
    return 0;
}