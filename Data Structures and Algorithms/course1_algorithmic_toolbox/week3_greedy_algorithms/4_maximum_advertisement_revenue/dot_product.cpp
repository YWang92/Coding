#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert> 

using std::vector;


/**
 * @brief Computes the maximum dot product between two vectors of integers, representing clicks and prices. 
 * The function sorts both vectors in descending order and multiplies corresponding elements to calculate the maximum dot product.
 * 
 * @param clicks Vector containing the number of clicks.
 * @param prices Vector containing the price values.
 * @return The maximum dot product of the two vectors.
 * 
 * @pre The size of both vectors should be equal and not exceed 1000. Each element in the vectors should be in the range [0, 100000].
 */


long long max_dot_product(vector<int> clicks, vector<int> prices) {
  // Assert that both vectors have the same size and meet the preconditions.
  assert(clicks.size() == prices.size());
  assert(clicks.size() <= 1000);
  
  // Check that each element of both vectors meets the precondition.
  for (int i = 0; i < clicks.size(); i++) {
    assert(0 <= clicks[i] && clicks[i] <= 100000);
    assert(0 <= prices[i] && prices[i] <= 100000);
  }

  // Sort both vectors in descending order.
  std::sort(clicks.begin(), clicks.end(), std::greater<int>());
  std::sort(prices.begin(), prices.end(), std::greater<int>());

  // Calculate the maximum dot product
  long long result = 0;
  for (size_t i = 0; i < clicks.size(); i++) {
    result += ((long long) clicks[i]) * prices[i]; // Cast to long long to avoid overflow
  }
  return result;
}


void run_test_case(vector<int> clicks, vector<int> prices, long long expected) {
    long long result = max_dot_product(clicks, prices);
    
    std::cout << "Test case: clicks = {";
    for (size_t i = 0; i < clicks.size(); ++i) {
        std::cout << clicks[i];
        if (i < clicks.size() - 1) {
            std::cout << ", ";
        }
    }
    
    std::cout << "}, prices = {";
    for (size_t i = 0; i < prices.size(); ++i) {
        std::cout << prices[i];
        if (i < prices.size() - 1) {
            std::cout << ", ";
        }
    }
    
    std::cout << "}, expected = " << expected << "\n";
    std::cout << "Result: " << result << "\n";
    
    if (result != expected) {
        std::cout << "WRONG\n";
        std::exit(1);
    } else {
        std::cout << "OK\n";
    }
}

void test_function() {
    run_test_case({1, 3, 5}, {2, 4, 6}, 44); // 5*6 + 3*4 + 1*2 = 30 + 12 + 2 = 44
    run_test_case({0, 0, 0}, {1, 1, 1}, 0); // 0*1 + 0*1 + 0*1 = 0
    run_test_case({100, 2000, 200, 300}, {1, 5, 10, 30}, 64100); // 30*2000 + 10*300 + 5*200 + 1*100 = 60000 + 3000 + 1000 + 100 = 64100
    // Add more test cases here
}


int main() {
  size_t n;
  std::cin >> n; // Input the size of vectors

  if (n == -10) {
    test_function();
    return 0;
  }
  
  vector<int> a(n), b(n); // Declare vectors a and b of size n
  
  // Input the elements of vector a
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  
  // Input the elements of vector b
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  // Output the maximum dot product of vectors a and b
  std::cout << max_dot_product(a, b) << std::endl;
}
