#include <iostream>
#include <vector>
#include <string>
#include "StringData.h"

// Binary Search Algorithm
int binary_search(const std::vector<std::string>& sequence, const std::string& item) {
    int begin_index = 0;
    int end_index = sequence.size() - 1;

    while (begin_index <= end_index) {
        int midpoint = (begin_index + end_index) / 2;
        std::string midpoint_value = sequence[midpoint];

        if (midpoint_value == item) {
            return midpoint; // Return index if found
        } else if (midpoint_value < item) {
            begin_index = midpoint + 1;
        } else {
            end_index = midpoint - 1;
        }
    }

    return -1; // Return -1 if item not found
}

// Linear Search Algorithm
int linear_search(const std::vector<std::string>& sequence, const std::string& item) {
    for (size_t i = 0; i < sequence.size(); ++i) {
        if (sequence[i] == item) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if item not found
}

int main() {
    std::vector<std::string> data_set = getStringData();
    std::string test_string = "zzzzz";

    // Binary Search Execution
    long long start_time = systemTimeNanoseconds();
    int binary_index = binary_search(data_set, test_string);
    long long end_time = systemTimeNanoseconds();
    std::cout << "String tested using Binary Search: " << test_string << " index: " << binary_index << std::endl;
    std::cout << "Execution Time (Binary Search): " << (end_time - start_time) << " milliseconds\n" << std::endl;

    // Linear Search Execution
    start_time = systemTimeNanoseconds();
    int linear_index = linear_search(data_set, test_string);
    end_time = systemTimeNanoseconds();
    std::cout << "String tested using Linear Search: " << test_string << " index: " << linear_index << std::endl;
    std::cout << "Execution Time (Linear Search): " << (end_time - start_time) << " milliseconds" << std::endl;

    return 0;
}