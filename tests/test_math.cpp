#include <iostream>
#include "my_lib/math_utils.hpp"

int main() {
    int error = 0;
    
    if (my_lib::add(2, 3) != 5) {
        std::cerr << "FAIL: add(2, 3) expected 5, but got " << my_lib::add(2, 3) << "\n";
        error++;
    }
    if (my_lib::add(-2, 4) != 2) {
        std::cerr << "FAIL: add(-2, 4) expected 2, but got " << my_lib::add(-2, 4) << "\n";
        error++;
    }
    if (my_lib::add(0, 0) != 0) {
        std::cerr << "FAIL: add(0, 0) expected 0, but got " << my_lib::add(0, 0) << "\n";
        error++;
    }
    if (error > 0) {
        std::cerr << "Unit test FAILED with " << error << " error(s) \n";
        return 1;
    }
    std::cout << "All unit tests PASSED successfully \n";

    return 0;
}