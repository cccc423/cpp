#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 

void generate_password(bool hasDigits, bool hasLetters, bool hasUppercaseLetters, bool hasSpecialSymbols, int passwordLength);

int main() {
    bool hasDigits = 0;
    bool hasLetters = 0;
    bool hasUppercaseLetters = 0;
    bool hasSpecialSymbols = 0;
    int passwordLength = 0;
    std::string choice;

    std::srand(std::time(0));

    while (true) {
        system("cls");

        // text menu
        std::cout << "password generator\n";
        std::cout << std::boolalpha;
        std::cout << "1. has digits = " << hasDigits << "\n";
        std::cout << "2. has letters = " << hasLetters << "\n";
        std::cout << "3. has uppercase letters = " << hasUppercaseLetters << "\n";
        std::cout << "4. has special symbols = " << hasSpecialSymbols << "\n";
        std::cout << "user choice (0 = quit, 9 = run generator) >> ";
        std::cin >> choice;

        // boolean switch for options
        if (choice == "1") { hasDigits = !hasDigits; } 
        else if (choice == "2") { hasLetters = !hasLetters; } 
        else if (choice == "3") { hasUppercaseLetters = !hasUppercaseLetters; } 
        else if (choice == "4") { hasSpecialSymbols = !hasSpecialSymbols; } 
        else if (choice == "0") { return 0; }
        else if (choice == "9") {
            // checking amount of selected options
            if (!hasDigits && !hasLetters && !hasUppercaseLetters && !hasSpecialSymbols) {
                std::cout << "error: No options selected";
                system("pause");
            } else {
                std::cout << "enter length of password >> ";
                std::cin >> passwordLength;
                std::cin.ignore();

                // checking password length input
                while (passwordLength <= 0) {
                    std::cout << "error: Invalid password length. Try again >> ";
                    std::cin >> passwordLength;
                    std::cin.ignore();
                }

                generate_password(hasDigits, hasLetters, hasUppercaseLetters, hasSpecialSymbols, passwordLength);

                // re-generate password cycle
                while (true) {
                    std::cout << "try again? (Y/N) >> ";
                    std::cin >> choice;

                    if (choice == "Y" || choice == "y") { 
                        generate_password(hasDigits, hasLetters, hasUppercaseLetters, hasSpecialSymbols, passwordLength); 
                    } else {
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

void generate_password(bool hasDigits, bool hasLetters, bool hasUppercaseLetters, bool hasSpecialSymbols, int passwordLength) {
    const std::string digits = "0123456789";
    const std::string letters = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string special = "!@#$%^&*()-_=+[]{};:,.<>?/|\\";
    std::string password = "";
    std::string alphabet = "";
    int alphabet_length = 0;
    char generated_char;

    // alphabet generation
    if (hasDigits) { alphabet += digits; alphabet_length += 10; }
    if (hasLetters) { alphabet += letters; alphabet_length += 26; }
    if (hasUppercaseLetters) { alphabet += uppercase; alphabet_length += 26; }
    if (hasSpecialSymbols) { alphabet += special; alphabet_length += 28; }

    // password generation
    for (int i = 0; i < passwordLength; i++) {
        generated_char = alphabet[std::rand() % alphabet_length];
        password.push_back(generated_char);
    }
    
    std::cout << password << "\n";
}