// https://www.hackerrank.com/contests/isspc/challenges/find-the-gcd-1-1/problem

/*
  You are given three number X,Y,Z. Find the GCD of (X^Z + Y^Z) and (Y - X).
  It is guaranteed that X < Y and (Y - X) <= 10^6.

  Input Format
  The first line of the input conatain a single integer T, the number of
  testcase. Each of next T line contain three integer X,Y,Z.

  Constraints
  1 <= T <= 100
  1 <= X,Y,Z <= 10^9

  It is guaranteed that X < Y and (Y - X) <= 10^6.

  Output Format
  Print a single integer GCD of (X^Z + Y^Z) and (Y - X).

  Sample Input
  2
  2 4 2
  1 6 3

  Sample Output
  2
  1

  Explanation
  Here, X = 2, Y = 4, Z = 2;
  Diff = (4 - 2) = 2
  (2^2 + 4^2) = (4 + 16) = 20
  GCD(2,20) = 2
*/

/*

  #+ATHOUR: Likhon Barai
  #+EMAIL:  <likhonhere007@gmail.com>

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll gcd(ll a, ll b) {
  if (b)
    while ((a %= b) && (b %= a))
      ;
  return (a + b);
}
#define TT                                                                     \
  int T;                                                                       \
  cin >> T;                                                                    \
  while (T--)

const ll MOD = 1e9 + 7;
ll expo(ll base, ll pow) {
  ll ans = 1;
  while (pow) {
    if (pow & 1) {
      ans = ans * base % MOD;
    }
    base = base * base % MOD;
    pow >>= 1;
  }
  return ans;
}

ll powmod(ll a, ll b, ll c) {
  ll r = 1;
  while (b != 0) {
    if (b & 1)
      r = (ll(r) * a) % c;
    a = (ll(a) * a) % c;
    b >>= 1;
  }
  return r;
}

int32_t main() {
  long long x, y, z, a, b;

  TT {
    cin >> x >> y >> z;
    a = powmod(x, z, y - x);
    b = powmod(y, z, y - x);
    cout << gcd(a + b, y - x) << "\n";
  }

  return 0;
}
