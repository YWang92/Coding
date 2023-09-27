#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;


/**
 * @brief Finds the minimum number of points such that each segment contains at least one common point.
 * 
 * @param segments A reference to a vector containing all the segments.
 * @return A vector containing the optimal points which are common to the segments.
 */

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here

  //sort segments by end point
  std::sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b) {
    return a.end < b.end;
  });

  //initialize current point to the end of the first segment
  int currentPoint = segments[0].end;
  points.push_back(currentPoint);
  for (size_t i = 1; i < segments.size(); ++i) {
    if (currentPoint < segments[i].start) {
      currentPoint = segments[i].end;
      points.push_back(currentPoint);
    } else {
      continue;}
  }
  return points;
}


void run_test_case(vector<Segment> segments, vector<int> expected) {
    vector<int> result = optimal_points(segments);
    std::cout << "Test case: segments = {";
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cout << "{" << segments[i].start << ", " << segments[i].end << "}";
        if (i < segments.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}, expected points = {";
    for (size_t i = 0; i < expected.size(); ++i) {
        std::cout << expected[i];
        if (i < expected.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
    std::cout << "Result: {" ;
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
    run_test_case({{1, 3}, {2, 5}, {3, 6}}, {3});
    run_test_case({{4, 7}, {1, 3}, {2, 5}, {5, 6}}, {3, 6});
    run_test_case({{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}}, {2, 4, 6});
}


int main() {
  int n;
  std::cin >> n;

  if (n == -10) {
    test_function();
    return 0;
  }

  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
