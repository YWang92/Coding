#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

/**
 * @brief Constructs the largest possible number by concatenating the given list of non-negative integers.
 * 
 * @param a Vector containing string representations of the non-negative integers.
 * @return The largest number (as a string) that can be constructed by the given concatenation.
 */


// Function to find the largest number that can be formed by concatenating the strings in the input vector.
string largest_number(vector<string> a) {
  // Sorts the strings based on the condition a + b > b + a, so that the concatenated result is the largest possible number.
  std::sort(a.begin(), a.end(), [](const string& a, const string& b) {
    return a + b > b + a;
  });

  std::stringstream ret;
  // Concatenates the sorted strings.
  for (const string& str : a) {
    ret << str;
  }

  string result;
  ret >> result;
  // Returns the concatenated result as a string.
  return result;
}


void run_test_case(vector<string> input, string expected) {
    string result = largest_number(input);
    std::cout << "Test case: input = {";
    for (size_t i = 0; i < input.size(); ++i) {
        std::cout << input[i];
        if (i < input.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}, expected = \"" << expected << "\"\n";
    std::cout << "Result: \"" << result << "\"\n";
    
    if (result != expected) {
        std::cout << "FAIL\n";
        std::exit(1);
    } else {
        std::cout << "PASS\n";
    }
}

void test_function() {
    run_test_case({"21", "2"}, "221");
    run_test_case({"9", "4", "6", "1", "9"}, "99641");
    run_test_case({"23", "232"}, "23232");
    run_test_case({"12", "121"}, "12121");
    run_test_case({"5", "56"}, "565");
    run_test_case({"830", "8308"}, "8308830");
    run_test_case({"3", "30", "34", "5", "9"}, "9534330");
    // Add more test cases as needed
}


int main() {
  int n;
  std::cin >> n;
  if (n == -10) {
    test_function();
    return 0;
  }

  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
