#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size, minDays, maxTemp;
        cin >> size >> minDays >> maxTemp;
        vector<int> v(size);
        for (int i = 0; i < size; i++)
        {
            cin >> v[i];
        }
        long long ans = 0;
        int i = 0, j = 0;
        while (j < size)
        {
            if (v[j] <= maxTemp)
            {
                j++;
            }
            else
            {
                int len = j - i;
                if (len >= minDays)
                {
                    long long count = len - minDays + 1;
                    ans += count * (count + 1) / 2;
                }
                j++;
                i = j;
            }
        }
        int len = j - i;
        if (len >= minDays)
        {
            long long count = len - minDays + 1;
            ans += count * (count + 1) / 2;
        }

        cout << ans << endl;
    }
    return 0;
}
