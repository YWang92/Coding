#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}


int gcd_fast(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd_fast(b, a % b);
}

void test_solution(int max_test = 1000) {
  int i = 0;
  while (true) {
    int a = rand() % 1000000000 + 1;
    int b = rand() % 1000000000 + 1;
    std::cout << a << ' ' << b << '\n';
    int res1 = gcd_naive(a, b);
    int res2 = gcd_fast(a, b);
    i++;
    if (res1 != res2) {
      std::cout << "Wrong answer: " << res1 << ' ' << res2 << '\n';
      break;
    } 
    else if(i == max_test) {
        std::cout << "All tests are OK!\n";
        break;
    }
    else {
      continue;
    }
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;

  test_solution();
  return 0;
}
