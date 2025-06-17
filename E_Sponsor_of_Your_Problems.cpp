#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

#define rep(i,a,b) for(int i=a; i<b; ++i)
#define per(i,a,b) for(int i=a; i>b; --i)
#define each(x,a) for(auto &x : a)

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

#ifdef LOCAL
#define debug(x) cerr << #x << " = "; _print(x); cerr << '\n';
#else
#define debug(x)
#endif

void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(string x) { cerr << '"' << x << '"'; }
void _print(char x) { cerr << '\'' << x << '\''; }
template<class T> void _print(vector<T> v) { cerr << '['; for(auto x : v) { _print(x); cerr << ' '; } cerr << ']'; }

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll l,r;cin>>l>>r;
    ll temp1=l;
    ll size=0;
    while(temp1>0){
        temp1/=10;
        size++;
    }
    if(l==r){
        cout<<size*2<<endl;
        return;
    }
    temp1 = l;
    ll temp2=r;
    vll L(size),R(size);
ll idx = size - 1;
while (temp1 > 0) {
    L[idx] = temp1 % 10;
    R[idx] = temp2 % 10;
    temp1 /= 10;
    temp2 /= 10;
    idx--;
}
    ll cnt=0;
    // rep(i,0,size){
    //     cout<<L[i]<<" ";
    // }
    // cout<<endl;
    // rep(i,0,size){
    //     cout<<R[i]<<" ";
    // }
    // cout<<endl;
    vll result(size);
    rep(i,0,size){
        if(L[i]==R[i] && L[i]==9){
            result[i]=0;
            if(result[i]==R[i]){
                cnt++;
            }
        }
        else if(L[i]-R[i]==0){
            cnt+=2;
            result[i]=L[i];
            // cout<<"loop1"<<" ";

        }
        else if(abs(L[i]-R[i])<=1){
            result[i]=L[i];
            cnt++;
            // cout<<"lppp2"<<" ";

        }

        else if(R[i] - L[i] > 0){
            result[i] = (R[i]+L[i])/2;
            // cout<<"lppp3"<<" ";

        }
        else if(R[i]-L[i]<0 ){
            if(L[i]==9){
                result[i]=0;
            }
            else{
                result[i] =L[i] + 1;
            }
            if(result[i]==R[i]){
                cnt++;
            }
            // if()
            // cout<<"lppp4"<<" ";

        }
        
    }
    cout<<cnt<<endl;

}

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}