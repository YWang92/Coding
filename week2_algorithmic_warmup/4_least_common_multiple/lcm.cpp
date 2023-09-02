#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd_fast(b, a % b);
}


long long lcm_fast(int a, int b) {
  return (long long) a * b / gcd_fast(a, b);
}

void test_function(int max_test = 100) {
  int i = 0;
  while (true) {
    int a = rand() % 1000000000 + 1;
    int b = rand() % 1000000000 + 1;
    std::cout << a << ' ' << b << '\n';
    long long res1 = lcm_naive(a, b);
    long long res2 = lcm_fast(a, b);
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
  // test_function();

  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
