#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll MaxPairwiseProduct(const std::vector<ll>& numbers) {
    ll max_product = 0;
    int n = numbers.size();

    ll first = 0, second = -1;

    for (int index = 0; index < n; ++index) {
        if (numbers[index] > first) {
            second = first;
            first = numbers[index];
        } else if (numbers[index] > second) {
            second = numbers[index];
        }
    }
    max_product = static_cast<ll>(first) * second;
    return max_product;
}

/*
int first = 5;
int a = ++first; // a is now 6, first is now 6
int b = first++; // b is now 6, first is now 7
*/


int main() {
    int n;
    std::cin >> n;
    std::vector<ll> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
