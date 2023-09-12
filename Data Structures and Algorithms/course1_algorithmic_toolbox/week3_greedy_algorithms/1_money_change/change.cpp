#include <iostream>

/**
 * Compute the minimum number of coins needed
 * to change the given value into coins with de-
 * nominations 1, 5, and 10.
*/
int get_change(int m) {
  int n = 0;

  n += m / 10;
  m %= 10;
  n += m / 5;
  m %= 5;
  n += m;

  return n ;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
