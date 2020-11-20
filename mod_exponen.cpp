#include <bits/stdc++.h>
#define ll long long int

const int SIZE = 1e6 + 5;

using namespace std;

ll mod_exponentiation(int x, int y, int m=1e9 + 7) {
  ll result = 1;
  if (y == 0)
    return 1;
  x = x % m;
  while (y > 0) {
    if (y%2 == 1)
      result = (result * x) % m;
    x = (x * x) % m;
    y = y/2;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  printf("%d ", mod_exponentiation(2, 15));
  return 0;
}
