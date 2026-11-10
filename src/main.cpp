#include <iostream>

#include "my_lib/math_utils.hpp"

int main() {
    int ket_qua = my_lib::add(5, 6);
    std::cout << "Ket qua: " << ket_qua << "\n";
    return 0;
}