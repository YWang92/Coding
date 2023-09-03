#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int previous = 0, current = 1, tmp_previous;

    for (int i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}

void test_function(){
    for (int i = 0; i < 20; ++i) {
        int naive = get_fibonacci_last_digit_naive(i);
        int fast = get_fibonacci_last_digit_fast(i);
        if (naive != fast) {
            std::cout << "Wrong answer: " << naive << ' ' << fast << '\n';
            break;
        } else {
           continue;
        }
    }
    std::cout << "All tests are OK!\n";
}

int main() {
    test_function();
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
