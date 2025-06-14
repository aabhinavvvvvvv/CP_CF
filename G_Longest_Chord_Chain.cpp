#include <bits/stdc++.h>
using namespace std;

// Function to check if two chords intersect
bool isIntersect(pair<int, int> a, pair<int, int> b) {
    int a1 = a.first, a2 = a.second;
    int b1 = b.first, b2 = b.second;
    if (a1 > a2) swap(a1, a2);
    if (b1 > b2) swap(b1, b2);
    return (a1 < b1 && b1 < a2 && a2 < b2) || (b1 < a1 && a1 < b2 && b2 < a2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<bool> used(2 * n + 1, false);
    vector<pair<int, int>> chords;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        chords.emplace_back(a, b);
        used[a] = used[b] = true;
    }

    // Add remaining points as new chords to complete the circle
    vector<int> unused;
    for (int i = 1; i <= 2 * n; ++i) {
        if (!used[i]) unused.push_back(i);
    }

    int m = unused.size();
    for (int i = 0; i < m / 2; ++i) {
        chords.emplace_back(unused[i], unused[i + m / 2]);
    }

    // Count intersections
    int total = 0;
    for (int i = 0; i < chords.size(); ++i) {
        for (int j = i + 1; j < chords.size(); ++j) {
            if (isIntersect(chords[i], chords[j])) {
                ++total;
            }
        }
    }

    cout << total << '\n';
    return 0;
}
