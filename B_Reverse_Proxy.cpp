#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> X(Q);
    for(int i = 0; i < Q; ++i) {
        cin >> X[i];
    }
    
    vector<int> boxCount(N + 1, 0); 
    vector<int> result;

    for(int i = 0; i < Q; ++i) {
        if (X[i] >= 1) {
            boxCount[X[i]]++;
            result.push_back(X[i]);
        } else {
            int minCount = 1e9;
            int minBox = -1;
            for (int j = 1; j <= N; ++j) {
                if (boxCount[j] < minCount) {
                    minCount = boxCount[j];
                    minBox = j;
                }
            }
            boxCount[minBox]++;
            result.push_back(minBox);
        }
    }

    for (int box : result) {
        cout << box<<" ";
    }

    return 0;
}
