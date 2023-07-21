#include <string>
#include <iostream>

// Note: there are 26 letters in the alphabet
std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
std::string cipher = "zyxwvutsrqponmlkjihgfedcba";



std::string encode (std::string message){

    std::string encoded_message = "";
        
    for (int i = 0; i < message.size(); ++i){
        
        encoded_message += cipher[alphabet.find(message[i])];
        
        if ( (i + 1) % 5 == 0) {
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
