#include <iostream>
#include <vector>
using std::vector;
#include <cmath>

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}


long long get_sum(vector<long long> fib, long long n) {
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

    return sum;
}


int get_fibonacci_partial_sum(long long m, long long n) {
    std::vector<long long> fib;
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

    long long sum = get_sum(fib, n) - get_sum(fib, m-1);
    return sum % 10;
}
/**
 * Side note:
 * llabs(long long int), labs(long int), abs(int) are used to get the absolute value of a number.
*/

void test_function(int max_test = 1000) {
    int i = 0;
    while (true) {
        long long from = rand() % 50 + 1;
        long long to = rand() % 50 + 1;
        if (from > to) {
            long long temp = from;
            from = to;
            to = temp;
        }
        std::cout << from << ' ' << to << '\n';
        int res1 = get_fibonacci_partial_sum_naive(from, to);
        int res2 = get_fibonacci_partial_sum(from, to);
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
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
