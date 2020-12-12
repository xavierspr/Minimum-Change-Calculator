#include <iostream>
#include <memory>
#include <cmath>
#include "Change.hpp"

bool calculateChange(uint32_t sum);
auto p_change = std::make_shared<Change>();

int main(int argc, char* argv[]) {
    std::cout << "Please enter the sum given to the cashier (integer) : " << std::endl;
    uint32_t sum;
    std::cin >> sum;
    if (calculateChange(sum)) {
        std::cout << "The cashier will return " << p_change->ten << " ten bill(s), " <<
                     p_change->five << " five bill(s) and " << p_change->two << " two coin(s)." << std::endl;
    }
    else {
        std::cout << "Failed to compute the change to give back." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

bool calculateChange(uint32_t sum) {
    if ((sum < 2) || (sum == 3))
        return false; // obviously impossible to compute

    uint32_t rest;
    if ((sum % 2) == 0) { // if even number
        // go the easy way: do all in 2-coins then optimize
        p_change->two = static_cast<uint32_t>(sum / 2);
        // Optimize
        p_change->ten = static_cast<uint32_t>(p_change->two / 5);
        p_change->two -= (5 * p_change->ten);
    }
    else { // if odd number
        // do some weird shit
        p_change->five = 1; // gonna need this
        rest = sum - 5;
        p_change->two = static_cast<uint32_t>(rest / 2);
        p_change->ten = static_cast<uint32_t>(p_change->two / 5);
        p_change->two -= (5 * p_change->ten);
    }
    
    return true;
}
