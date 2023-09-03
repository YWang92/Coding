#include <iostream>
#include <cassert>
#include <vector>

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    // write your code here
    std::vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);

    for (int i = 2; i <= n; ++i) {
        long long current = fib[i-1] + fib[i-2];
        fib.push_back(current);
    }

    return fib[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;

    // std::cout << fibonacci_naive(n) << '\n';
    // test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
