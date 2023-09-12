#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using std::vector;

/**
 * @brief Calculates the maximum value that can be obtained from items with given weights and values, 
 * considering a total capacity constraint.
 * 
 * @param capacity The maximum weight capacity of the knapsack.
 * @param weights Vector containing the weights of the items.
 * @param values Vector containing the values of the items.
 * @return The maximum total value that can be obtained under the capacity constraint.
 */
double get_optimal_value(int capacity, const vector<int>& weights, const vector<int>& values) {
  double totalValue = 0.0;

  // Create a vector of tuples where each tuple contains the value-to-weight ratio and the weight of an item
  vector<std::tuple<double, int>> valueToWeightRatios;
  for (int i = 0; i < values.size(); ++i) {
    double ratio = static_cast<double>(values[i]) / weights[i];
    valueToWeightRatios.push_back(std::make_tuple(ratio, weights[i]));
  }

  // sort(value_weight.begin(), value_weight.end(), std::greater<std::tuple<double, int>>());
  // sort(value_weight.begin(), value_weight.end(), std::less<std::tuple<double, int>>());

  // Sort the items by their value-to-weight ratio in descending order
  std::sort(valueToWeightRatios.begin(), valueToWeightRatios.end(),
      [](const std::tuple<double, int>& a, 
             const std::tuple<double, int>& b) {
        return std::get<0>(a) > std::get<0>(b);
      });

  // Iterate through the sorted items to find the most valuable combination within the capacity constraint
  for (const auto& item : valueToWeightRatios) {
    if (capacity == 0) {
      break;
    }

    int itemWeight = std::get<1>(item);
    double itemValuePerWeight = std::get<0>(item);

    if (capacity >= itemWeight) {
      totalValue += itemValuePerWeight * itemWeight;
      capacity -= itemWeight;
    } else {
      totalValue += itemValuePerWeight * capacity;
      capacity = 0;
    }
  }

  return totalValue;
}
                       

void test_function() {
  int n = 1, capacity = 1000;
  vector<int> values(n);
  values = {500};
  vector<int> weights = {30};
  double optimal_value = get_optimal_value(capacity, weights, values);
  std::cout << "optimal_value: " << optimal_value << std::endl;
  std::cout << "expected: 500" << std::endl;

  if ( (optimal_value - 500) > 1e-3) {
    std::cout << "WRONG" << std::endl;
    std::exit(1);
  }
  else {
    std::cout << "OK" << std::endl;
  }
}


int main() {
  // test_function();
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

