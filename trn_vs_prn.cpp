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

















vector<double> times;

int lastbit(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum & 1;
}
void solve() {
    rep(i, 0, 1024){
        auto begin = chrono::high_resolution_clock::now();
        time_t t = time(NULL);
        int random_number = (t * 1103515245 + 12345) & 0x7FFFFFFF;

        int min = 100000;
        int max = 1000000;

        int range = min + (random_number % (max - min + 1));
        rep(i, 0, range){
        }
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        times.pb(lastbit(elapsed.count() * 1e-2));
    }
    vector<int> final;
    for(int i = 0; i < times.size(); i += 2){
        if(i + 1 < times.size() && (times[i] == 0 && times[i + 1] == 0) || (times[i] == 1 && times[i + 1] == 1)){
            continue;
        }
        else if(i + 1 < times.size() && times[i] == 0 && times[i + 1] == 1){
            final.pb(0);
        }
        else if(i + 1 < times.size() && times[i] == 1 && times[i + 1] == 0){
            final.pb(1);
        }
    }
    debug(final);
    // Results by True Random Generator
    // shannon entropy formula
    cout << "RESULTS BY TRUE RANDOM GENERATOR" << endl;
    long double shannon_entropy;
    long double zeros = 0, ones = 0;
    for(int i = 0; i < final.size(); i++){
        if(final[i] == 0){
            zeros++;
        }
        else{
            ones++;
        }
    }

    shannon_entropy = -((zeros / final.size()) * log2(zeros / final.size()) + (ones / final.size()) * log2(ones / final.size()));
    cout << "Shannon Entropy: " << shannon_entropy << endl;

    // chi square test
    long double expected = final.size() / 2.0;
    long double chi_square = ((zeros - expected) * (zeros - expected)) / expected + ((ones - expected) * (ones - expected)) / expected;
    cout << "Chi-Square: " << chi_square << endl;
    // Results by Pseudo Random Generator
    cout << "RESULTS BY PSEUDO RANDOM GENERATOR" << endl;

    times.clear();
    rep(i, 0, 1024){
        auto begin = chrono::high_resolution_clock::now();
        int t = rand();
        int min = 100000;
        int max = 1000000;

        int range = min + (t % (max - min + 1));
        rep(i, 0, range){
        }
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        times.pb(lastbit(elapsed.count() * 1e-2));
    }
    final.clear();
    for(int i = 0; i < times.size(); i += 2){
        if(i + 1 < times.size() && (times[i] == 0 && times[i + 1] == 0) || (times[i] == 1 && times[i + 1] == 1)){
            continue;
        }
        else if(i + 1 < times.size() && times[i] == 0 && times[i + 1] == 1){
            final.pb(0);
        }
        else if(i + 1 < times.size() && times[i] == 1 && times[i + 1] == 0){
            final.pb(1);
        }
    }
    debug(final);
    // Results by Pseudo Random Generator
    // shannon entropy formula
    shannon_entropy;
    zeros = 0, ones = 0;
    for(int i = 0; i < final.size(); i++){
        if(final[i] == 0){
            zeros++;
        }
        else{
            ones++;
        }
    }

    shannon_entropy = -((zeros / final.size()) * log2(zeros / final.size()) + (ones / final.size()) * log2(ones / final.size()));
    cout << "Shannon Entropy: " << shannon_entropy << endl;

    // chi square test
    expected = final.size() / 2.0;
    chi_square = ((zeros - expected) * (zeros - expected)) / expected + ((ones - expected) * (ones - expected)) / expected; 
    cout << "Chi-Square: " << chi_square << endl;
    }



int main() {
    fastIO();
    freopen("Error.txt", "w", stderr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int t = 1;
    // cin >> t;
    while (t--) solve();


    return 0;
}