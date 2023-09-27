#include <iostream>
#include <vector>

using std::vector;

/**
 * @brief Decomposes a given number into a sum of unique natural numbers.
 * 
 * @param n The integer to be decomposed.
 * @return A vector containing the natural numbers whose sum is equal to the input number.
 */

vector<int> optimal_summands(int n) {
  vector<int> summands;
  
  // Loop through 1 to n to find the optimal summands
  for (size_t i = 1; i <= n; ++i) {
    if (n - i < i + 1) {  // If further addition will include duplicate natural numbers
      summands.push_back(n);  // Include the remaining value to the summands and break
      break;
    } else {
      n -= i;  // Reduce n by the value of i
      summands.push_back(i);  // Add i to the summands
    }
  }

  return summands;  // Return the vector of optimal summands
}

void run_test_case(int n, vector<int> expected) {
    vector<int> result = optimal_summands(n);
    std::cout << "Test case: n = " << n << ", expected = {";
    for (size_t i = 0; i < expected.size(); ++i) {
        std::cout << expected[i];
        if (i < expected.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
    std::cout << "Result: {";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
    
    if (result != expected) {
        std::cout << "FAIL\n";
        std::exit(1);
    } else {
        std::cout << "PASS\n";
    }
}

void test_function() {
    run_test_case(6, {1, 2, 3});
    run_test_case(8, {1, 2, 5});
    run_test_case(80, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 14});
    // Add more test cases as needed
}


int main() {
  int n;
  std::cin >> n;  // Input integer to be decomposed

  if (n == -10) {
    test_function();
    return 0;
  }
  
  vector<int> summands = optimal_summands(n);  // Get the optimal summands
  
  // Print the size of the summands and the summands themselves
  std::cout << summands.size() << '\n';
  for (const auto& summand : summands) {
    std::cout << summand << ' ';
  }
}

