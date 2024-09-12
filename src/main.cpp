#include <cmath>
#include <cstdlib>
#include <iostream>

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, (a % b));
}

int non_r_gcd(int a, int b) {
  if (b == 0)
    return a;
  while (b != 0) {
    int rem = b;
    b = a % b;
    a = rem;
  }
  return a;
}
int gcd_t(int a, int b) {
  while (a != b) {
    if (a > b)
      a = a - b;
    else {
      b = b - a;
    }
  }
  return a;
}

int gcd_s(int a, int b) {
  while (b != 0) {
    int tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}


int x_gcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int gcd = x_gcd(b, (a % b), x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);

  return gcd;
}

bool rabin_mill(int n) {
  int k = __builtin_ctz(n - 1);

  int q = n >> k;
  // int d = q - 1;
  // while (q % 2 == 0) {
  //   q /= 2;
  //   k++;
  // }

  for (int i = 1; i < 9; i++) {
    int a = rand() % n;;
    if ((static_cast<int>(std::pow(a, q)) % n) != 1)
    {
        if (static_cast<int>(std::pow(a,(k * q))) % n == (n - 1))
            return true;
    }
  }
  return false;
}


int main(int argc, char *argv[])
{

  bool is_prime = rabin_mill(561);
  std::cout << std::boolalpha << is_prime << '\n';
  return 0;
}

/*
 * Test for primality using Rabin-Miller Algorithm
 * Test(n)
 * 1. find integers k, q, with k > 0, q odd, so that
 *    (n - 1 = 2^k * q);
 * 2. Select a random integer a, 1 < a < n - 1
 * 3. if a ^ q mod n = 1, then return "inconclusive"
 * 4. for j = 0 to k - 1 do
 * 5 .if (a^q)^k mod n = n - 1 then return "inconclusive"
 * 6. return "composite"
 */

/*
 * Example n = 29
 * n - 1 = 28 = 2 ^ 2 * 7;  q = 7, k = 2
 * choose a = 10
 * compute 10^7 % 29 = 17, continue;
 * next calculation finds that:
 * (10^7)^2 % 29 = 28, return "inconclusive"
 */
