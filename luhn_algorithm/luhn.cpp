#include "luhn.h"

#include <iostream>

int main() {
    
    // Accept a string containing a number
    std::string number;
    std::getline(std::cin, number);
    
    // Strip all white spaces from string
    number = strip_spaces(number);
    std::cout << number << '\n';
    
    // Check if it's a valid number
    std::cout << valid(number) << '\n';
    
    return 0;
    
}
