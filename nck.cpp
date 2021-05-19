#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define PRIME 1000000007

ll modPow(ll a, ll x, ll p) {
    //calculates a^x mod p in logarithmic time.
    ll res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

ll modInverse(ll a, ll p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}
ll modBinomial(ll n, ll k, ll p) {
// calculates C(n,k) mod p (assuming p is prime).

    ll numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    ll denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}

ll test_case() {
    ll n, m, k;
    ll count = 0;
    cin>> n>> m>> k;
    ll a[n];
    REP(i, 0, n)
        cin>> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        auto up = upper_bound(a, a+n, a[i] + k);
        ll index = (up - a) - 1;
        count = (count + modBinomial(index - i, m-1, PRIME)) % PRIME;
    }
    return count;
}

int main() {
    int t = 1;
    cin>> t;
    while (t--){
		// test_case();
        cout<<test_case();
        cout<<endl;
    }
    return 0;
}
