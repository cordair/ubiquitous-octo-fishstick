#include <string>
#include <iostream>

// Note: there are 26 letters in the alphabet
std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
std::string cipher = "zyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcba1234567890";



std::string encode (std::string message){

    std::string encoded_message = "";
        
    for (int i = 0; i < message.size(); ++i){
        
        if ( alphabet.find(message[i]) == -1) { // if a character is not in our alphabet, skip it
            continue;
        }
        encoded_message += cipher[alphabet.find(message[i])]; // otherwise, encode it according to cipher
        
        if ( (i + 1) % 5 == 0) { // make groups of 5 characters separated by a blank space
            encoded_message += " ";
        }
    }    
    
    return encoded_message;
}

    std::string decode (std::string message) {
        
        std::string decoded_message = "";
        
        for (int i = 0; i < message.size(); ++i) {
            if ( message[i] == ' ' ) {
                continue;
            }
            decoded_message += alphabet[cipher.find(message[i])];
        }
        
        return decoded_message;
    } 

    
 int main() {        
    
     std::string encoded_message = encode("abcdefg");
     
     std::cout << encoded_message << std::endl;
     
     std::string decoded_message = decode("zyxwv ut");
    
     std::cout << decoded_message << std::endl;
     
     return 0;
 }
