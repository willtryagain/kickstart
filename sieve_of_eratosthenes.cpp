#include <bits/stdc++.h>
#define ll long long int

const int SIZE = 1e6 + 5;

using namespace std;

vector<int> is_prime(SIZE+1, true);

void sieve(ll n) {
  is_prime[0] = false;
  is_prime[1] = false;
  for (ll i = 2; i*i <= n; i++) {
    if (is_prime[i]) {
      for (ll j = i*i; j <= n; j += i)
        is_prime[j] = false;
    }
  }
}
int main(int argc, char const *argv[]) {
  sieve(100);
  for (size_t i = 1; i < 100; i++) {
    if (is_prime[i])
      printf("%d ", i);
  }
  sieve(1e6);
  return 0;
}
