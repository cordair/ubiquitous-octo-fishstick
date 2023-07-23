#include <string>
#include <cstring> // for argv[] in main()
#include <iostream>

// Note: there are 26 letters in the alphabet
std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
std::string cipher = "zyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcba1234567890";



std::string encode (std::string message){

    std::string encoded_message = "";
    int count_chars = 0;
        
    for (int i = 0; i < (int) message.size(); ++i){ // (int) to convert to int and compare between equal types
        
        if (alphabet.find(message[i]) == -1) { // if a character is not in our alphabet, skip it
            continue;
        }
        
        if ( count_chars == 5) { // make groups of 5 characters separated by a blank space
            encoded_message += " ";
            count_chars = 0; // reset counter
        }
        
        encoded_message += cipher[alphabet.find(message[i])]; // otherwise, encode it according to cipher
    }    
    
    return encoded_message;
}

    std::string decode (std::string message) {
        
        std::string decoded_message = "";
        
        for (int i = 0; i < (int) message.size(); ++i) {
            if ( message[i] == ' ' ) {
                continue;
            }
            decoded_message += alphabet[cipher.find(message[i])];
        }
        
        return decoded_message;
    } 

    
 int main(int argc, char *argv[]) {
    
    if (argc != 3) { // first value in argv is name of program, second is first argument and third is second argument
        std::cout << argv[0] << " requires two arguments: first encode or decode and second the message to encode or decode." << std::endl;
    } else if ( std::strcmp(argv[1], "encode") == 0 ) {
        std::string encoded_message = encode(argv[2]); // if argv[2] is a C style string instead of a C++ string... should types match? encode is expecting a <string>
        std::cout << encoded_message << std::endl;     
    } else if ( std::strcmp(argv[1], "decode") == 0 ) {
        std::string decoded_message = decode(argv[2]);
        std::cout << decoded_message << std::endl;
    } else {
        std::cout << "Enter either 'encode' or 'decode' as first argument." << std::endl;
    }

     return 0;
 }
