#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 1; i < n; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + previous;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    std::vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);

    for (long long i = 1; i < n; ++i) {
        int current = (fib[i] % 10) + (fib[i - 1] % 10);
        fib.push_back(current % 10);
        if (fib[i+1] == 1 && fib[i] == 0) {
            fib.pop_back();
            fib.pop_back();
            break;
        }
    }
    
    long long loop_cycle = (n+1) / fib.size();
    long long loop_rem   = (n+1) % fib.size();

    long long sum = 0;
    for (long long i = 0; i < fib.size(); ++i) {
        sum += fib[i] % 10;
    }
    sum *= loop_cycle;

    for (long long i = 0; i < loop_rem; ++i) {
        sum += fib[i] % 10;
    }

    return sum % 10;
}

void test_function(int max_test = 10000) {
    int i = 0;
    while (true) {
        long long n = rand() % 50 + 1;
        std::cout << n << '\n';
        int res1 = fibonacci_sum_naive(n);
        int res2 = fibonacci_sum_fast(n);
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
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
