
#include <iostream>
#include <cctype>

int strcmp_case_insensitive(const char* firstString, const char* secondString, bool spaceSkip = false) {

    while (*firstString && *secondString) {
        
        if (spaceSkip) {
            while (*firstString == ' ') {
                firstString++;
            }
            while (*secondString == ' ') {
                secondString++;
            }

        }

        char letterFirst = tolower(*firstString);
        char letterSecond = tolower(*secondString);

        if (letterFirst != letterSecond) {

            return letterFirst - letterSecond;

        }

        firstString++;
        secondString++;
    }

    if (spaceSkip) {

        while (*firstString == ' ') {
            firstString++;
        }
        while (*secondString == ' ') {
            secondString++;
        }

    }

    return *firstString - *secondString;

}

int main() {

    const char* firstStr = "String One";
    const char* secondStr = "string Two";
    const char* thirdStr = "string one";
    const char* fourthStr = "STRING ONE";
    const char* fifthStr = "Another";
    const char* sixthStr = "The Cool String";
    const char* seventhStr = "thecoolstring";
    const char* eighthStr = "   my cool   string";

    std::cout << "The comparison of \"" << firstStr << "\" and \"" << secondStr
              << "\" returns " << strcmp_case_insensitive(firstStr, secondStr) << ".\n";

    std::cout << "The comparison of \"" << firstStr << "\" and \"" << thirdStr
              << "\" returns " << strcmp_case_insensitive(firstStr, thirdStr) << ".\n";

    std::cout << "The comparison of \"" << firstStr << "\" and \"" << fourthStr
              << "\" returns " << strcmp_case_insensitive(firstStr, fourthStr) << ".\n";

    std::cout << "The comparison of \"" << secondStr << "\" and \"" << thirdStr
              << "\" returns " << strcmp_case_insensitive(secondStr, thirdStr) << ".\n";

    std::cout << "The comparison of \"" << firstStr << "\" and \"" << fifthStr
              << "\" returns " << strcmp_case_insensitive(firstStr, fifthStr) << ".\n";

    std::cout << "The comparison of \"" << sixthStr << "\" and \"" << seventhStr
              << "\" returns " << strcmp_case_insensitive(sixthStr, seventhStr, true) << ".\n";

    std::cout << "Comparison of \"" << eighthStr << "\" and \"" << seventhStr
              << "\" returns " << strcmp_case_insensitive(eighthStr, seventhStr, true) << ".\n";

    return 0;

}
