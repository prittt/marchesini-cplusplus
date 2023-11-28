#include "conta.h"

#include <sstream>

// int Conta(const std::string& str) {
//     int count = 0;
//     bool InWord = false;

//     for (char c : str) {
//         if (c != ' ' && !InWord) {
//             count++;
//             InWord = true;
//         } else if (c == ' ') {
//             InWord = false;
//         }
//     }

//     return count;
// }

int Conta(const std::string& str) {
    std::istringstream iss(str);
    std::string word;
    int count = 0;

    while(iss >> word) {
        count++;
    }

    return count;
}
