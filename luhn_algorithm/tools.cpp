#include "luhn.h"
#include <iostream>

std::string strip_spaces (std::string str) {
    
    std::string new_str = "";
    
    for (int i = 0; i < (int) str.size(); ++i) {
        if (str[i] != ' ') {
            new_str += str[i];
        }
    }
    
    return new_str;
}

bool validCharacters (std::string str) {
    
    for (int i = 0; i < (int) str.size(); ++i) {
        if ( convert_to_int(str[i]) == -1 ) {
            std::cout << "Detected invalid character in provided number: " << str[i] << '\n';
            std::cout << "Please, try again.\n";
            return false;
        }
    }

    return true;
}

int convert_to_int (char n) {
    if (n == '0') {
        return 0;
    } else if (n == '1') {
        return 1;
    } else if (n == '2') {
        return 2;
    } else if (n == '3') {
        return 3;
    } else if (n == '4') {
        return 4;
    } else if (n == '5') {
        return 5;
    } else if (n == '6') {
        return 6;
    } else if (n == '7') {
        return 7;
    } else if (n == '8') {
        return 8;
    } else if (n == '9') {
        return 9;
    } else { // invalid digit
        return -1;
    }
    
}

bool valid(std::string number) {
    int sumOfDigits = 0;
    bool a = false; // alternates between false and true to identify which digits have to be double (every other digit starting from the right)
    
    if ((int) number.size() <= 1) {
        return false;
    } else {
        int nextDigit;
        
        for (int i = (int) number.size() - 1; i >= 0; --i) {
            nextDigit = convert_to_int(number[i]);
            
            if (nextDigit == -1) { // invalid character
                return false;
            } else {
                if (a == true) {
                    if (convert_to_int(number[i]) * 2 > 9) {
                        sumOfDigits += convert_to_int(number[i]) * 2 - 9;
                    } else {
                        sumOfDigits += convert_to_int(number[i]) * 2;
                    }
                } else {
                    sumOfDigits += convert_to_int(number[i]);
                }
                a = !a;
            }
        }
        if (sumOfDigits % 10 == 0) {
            return true;
        } else {
            return false;
        }
    }
}
