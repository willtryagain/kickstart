#include <bits/stdc++.h>
#define ll long long int

const int SIZE = 1e6 + 5;

using namespace std;

int smallest_prime_factor[SIZE];

void get_smallest_prime_factor(ll n=1e6) {
  smallest_prime_factor[1] = 1;
  for (size_t i = 2; i < SIZE; i++)
    smallest_prime_factor[i] = i;
  for (size_t i = 4; i < SIZE; i += 2)
    smallest_prime_factor[i] = 2;
  for (size_t i = 3; i*i < SIZE; i++) {
    if (smallest_prime_factor[i] == i) {
      for (size_t j = i*i; j < SIZE; j += i) {
        if (smallest_prime_factor[j] == j)
          smallest_prime_factor[j] = i;
      }
    }
  }
}

vector<int> factorize(ll n) {
  vector<int> result;
  while (n > 1) {
    result.push_back(smallest_prime_factor[n]);
    n  = n / smallest_prime_factor[n];
  }
  return result;
}
int main(int argc, char const *argv[]) {
  get_smallest_prime_factor();
  vector<int> factors = factorize(12246);
  for (int factor : factors)
    printf("%d ", factor);
  return 0;
}
