/*
 * Competitive Programming Template
 * Author: Abhinav Gupta
 * GitHub: @aabhinavvvvvvv
 * MAHAKAL KI JAI
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define per(i,a,b) for(int i=a; i>b; --i)
#define each(x,a) for(auto &x : a)
#define sz(x) (int)(x).size()
#define fastIO() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void _print(int t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(string t) { cerr << '"' << t << '"'; }
void _print(char t) { cerr << '\'' << t << '\''; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }

template <typename T, typename V> void _print(pair<T, V> p);
template <typename T> void _print(vector<T> v);
template <typename T> void _print(set<T> v);
template <typename T> void _print(multiset<T> v);
template <typename T, typename V> void _print(map<T, V> v);

template <typename T, typename V>
void _print(pair<T, V> p) { cerr << '{'; _print(p.first); cerr << ", "; _print(p.second); cerr << '}'; }
template <typename T>
void _print(vector<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template <typename T>
void _print(set<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template <typename T>
void _print(multiset<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template <typename T, typename V>
void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) _print(i), cerr << " "; cerr << "]"; }
struct point{
    int x, y;
    char color;
    void update(int x, int y){
        swap(x, y);
    }
};
void solve() {
    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    a.color = 'A';
    b.color = 'B';
    c.color = 'C';
    if(a.x < a.y){
        swap(a.x, a.y);
    }
    if(b.x < b.y){
        swap(b.x, b.y);
    }
    if(c.x < c.y){
        swap(c.x, c.y);
    }
    ll area = a.x * a.y + b.x * b.y + c.x * c.y;
    ll side = sqrt(area);
    if(side * side != area){
        // cout << "FIRST";
        cout << -1 << endl;
        return;
    }
    if(a.x == side && a.x == b.x && a.x == c.x){
        if(a.y + b.y + c.y == a.x){
            cout << a.x << endl;
            for(int i = 0; i < a.y; i++){
                for(int j = 0; j < a.x; j++){
                    cout << a.color;
                }
                cout << endl;
            }
            for(int i = 0; i < b.y; i++){
                for(int j = 0; j < b.x; j++){
                    cout << b.color;
                }
                cout << endl;
            }
            for(int i = 0; i < c.y; i++){
                for(int j = 0; j < c.x; j++){
                    cout << c.color;
                }
                cout << endl;
            }
            return;
        }
        else{
            // cout << "SECOND";
            cout << -1 << endl;
            return;
        }
    }
    if(c.x > b.x){
        swap(b, c);
    }
    if(b.x > a.x){
        swap(a, b);
    }
    int remain = a.x - a.y;
    if(b.x == remain){
        swap(b.x, b.y);
    }
    if(c.x == remain){
        swap(c.x, c.y);
    }
    if(a.x == side && (b.x + c.x == a.x) && b.y == remain && c.y == remain){
        cout << a.x << endl;
        for(int i = 0; i < a.y; i++){
            for(int j = 0; j < a.x; j++){
                cout << a.color;
            }
            cout << endl;
        }
        for(int i = 0; i < remain; i++){
            for(int j = 0; j < b.x; j++){
                cout << b.color;
            }
            for(int j = 0; j < c.x; j++){
                cout << c.color;
            }
            cout << endl;
        }
        return;
    }
    // cout << "THIRD";
    cout << -1 << endl;
}

int main() {
    fastIO();
#ifdef LOCAL
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    auto begin = chrono::high_resolution_clock::now();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;

    return 0;
}