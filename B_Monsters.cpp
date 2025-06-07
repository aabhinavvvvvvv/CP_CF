#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        vector<pair<long long, int>> monsters; // (hits needed, index)

        for (int i = 0; i < n; ++i)
        {
            long long health;
            cin >> health;

            long long mod = health % k;
            if (mod == 0)
                mod = k;

            monsters.push_back({-mod, i + 1});
        }

        sort(monsters.begin(), monsters.end());

        for (auto &p : monsters)
            cout << p.second << " ";
        cout << "\n";
    }

    return 0;
}
