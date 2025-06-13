#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    // if (n <= 1) return false;
    // if (n <= 3) return true;
    // if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
        // if (n % i == 0 || n % (i + 2) == 0)
        //     return false;
    return true;
}

int nextPrimeWithMinDiff(int x, int d) {
    int candidate = x + d;
    while (!isPrime(candidate)) {
        ++candidate;
    }
    return candidate;
}

int main()
{
    int t;cin>>t;
    while(t--){
        int d;
        cin>>d;
        int start =1;
        int first = nextPrimeWithMinDiff(start,d);
        int second = nextPrimeWithMinDiff(first,d);
        int ans=first*second;
        cout<<ans<<endl;

    }
 return 0;
}