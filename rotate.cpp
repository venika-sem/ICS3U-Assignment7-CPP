// Copyright (c) 2022 Venika Sem All rights reserved

// Created by: Venika Sem
// Created on: Dec 2022
// This program translates anything to Pig Latin

#include <iostream>
#include <sstream>
#include <string>

std::string translateWordToPigLatin(const std::string& word) {
    std::string pigLatin;
    for (size_t i = 0; i < word.size(); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i'
        || word[i] == 'o' || word[i] == 'u') {
            pigLatin = word.substr(i) + "ay";
            break;
        } else {
            pigLatin = word.substr(i + 1) + word[i] + "ay";
        }
    }
    return pigLatin;
}

std::string translateToPigLatin(const std::string& str) {
    std::stringstream ss(str);
    std::string word, pigLatin;
    while (ss >> word) {
        pigLatin += translateWordToPigLatin(word) + " ";
    }
    return pigLatin;
}

int main() {
    std::string input;
    std::cout << "Enter a sentence to translate to Pig Latin: ";
    std::getline(std::cin, input);
    std::cout << std::endl;
    std::cout << translateToPigLatin(input) << std::endl;
    std::cout << std::endl;
    std::cout << "Done." << std::endl;
    return 0;
}
