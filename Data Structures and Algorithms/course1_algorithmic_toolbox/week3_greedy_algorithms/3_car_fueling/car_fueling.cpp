#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

/**
 * @brief Computes the minimum number of refills needed to travel a given distance with a given tank capacity,
 * considering a set of available fuel stops along the way.
 * 
 * @param dist The total distance to be traveled.
 * @param tank The maximum fuel capacity of the tank.
 * @param stops Vector containing the positions of fuel stops along the route.
 * @return The minimum number of refills needed to travel the given distance. Returns -1 if the journey is impossible.
 */

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int numRefills = 0;
    int currentRefill = 0;

    // Check edge cases: No stops and distance is either reachable or not
    if (stops.empty()) {
        return (dist <= tank) ? 0 : -1;
    }

    // Check if the first stop is unreachable
    if (stops[0] > tank) {
        return -1;
    }

    for (int i = 1; i < stops.size(); ++i) {
        int stop = stops[i];
        int refillToStop = stop - currentRefill;
        int stopToNextStop = stops[i] - stops[i-1];

        // Check if the distance between two consecutive stops exceeds the tank capacity
        if (stopToNextStop > tank) {
            return -1;
        } 

        if (refillToStop > tank) {
            currentRefill = stops[i-1];
            ++ numRefills;
        } 
    }
    
    // Check if the end is unreachable from the final stop
    int lastStopToEnd = dist - stops.back();
    if (lastStopToEnd > tank) {
        return -1;
    } 

    // Check if the end is unreachable from the current refill
    int refillToEnd = dist - currentRefill;
    if (refillToEnd > tank) {
        ++ numRefills;
    } 

    return numRefills;
}


// void test_function() {
//     int d = 500, m = 200, n = 4;
//     vector<int> stops(n);
//     stops = {100, 200, 300, 400};
//     int expected = 2;
//     int numRefills = compute_min_refills(d, m, stops);
//     std::cout << "numRefills: " << numRefills << std::endl;
//     std::cout << "expected:" << expected << std::endl;

//     if (numRefills != expected) {
//         std::cout << "WRONG" << std::endl;
//         std::exit(1);
//     }
//     else {
//         std::cout << "OK" << std::endl;
//     }
// }


void run_test_case(int d, int m, vector<int> stops, int expected) {
    int numRefills = compute_min_refills(d, m, stops);
    std::cout << "Test case: d = " << d << ", m = " << m << ", stops = {";
    for (size_t i = 0; i < stops.size(); ++i) {
        std::cout << stops[i];
        if (i < stops.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}, expected = " << expected << "\n";
    std::cout << "numRefills: " << numRefills << "\n";

    if (numRefills != expected) {
        std::cout << "WRONG\n";
        std::exit(1);
    } else {
        std::cout << "OK\n";
    }
}

void test_function() {
    run_test_case(500, 200, {100, 200, 300, 400}, 2);
    run_test_case(700, 200, {100, 200, 300, 400}, -1);
    run_test_case(100, 50, {25, 50, 75}, 1);
    // Add more test cases here
}



int main() {
    int d = 0;
    cin >> d;

    if (d == -10) {
        test_function();
        exit(0);
    }

    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;


    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
