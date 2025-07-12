#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

pll normalize(ll dy, ll dx) {
    if (dx == 0) return {1, 0}; 
    if (dy == 0) return {0, 1}; 
    ll g = gcd(abs(dy), abs(dx));
    dy /= g;
    dx /= g;
    if (dx < 0) dy = -dy, dx = -dx; 
    return {dy, dx};
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    set<set<int>> lines;

    for (int i = 0; i < n; ++i) {
        map<pair<pll, ll>, set<int>> lineMap;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            ll x1 = points[i].first, y1 = points[i].second;
            ll x2 = points[j].first, y2 = points[j].second;
            ll dx = x2 - x1, dy = y2 - y1;

            pll slope = normalize(dy, dx);

            ll intercept_numer = dy * x1 - dx * y1;
            ll intercept_denom = dx;
            ll g = gcd(abs(intercept_numer), abs(intercept_denom));
            intercept_numer /= g;
            intercept_denom /= g;
            if (intercept_denom < 0) {
                intercept_numer = -intercept_numer;
                intercept_denom = -intercept_denom;
            }

            pair<pll, ll> lineKey = {slope, intercept_numer};

            lineMap[lineKey].insert(i);
            lineMap[lineKey].insert(j);
        }

        for (auto a : lineMap) {
            if (a.second.size() >= 3) {
                lines.insert(a.second);
            }
        }
    }

    cout << lines.size() << endl;
    return 0;
}
