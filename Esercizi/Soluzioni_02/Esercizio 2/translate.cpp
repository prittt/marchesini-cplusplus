#include "translate.h"

void Translate(std::string& s, const std::string& from_lst, const std::string& to_lst) {
    if (from_lst.length() != to_lst.length()) {
        return;
    }
    for (char &c : s){  
        auto pos = from_lst.find(c);
        if (pos != std::string::npos) {
            c = to_lst[pos];
        }
    }

}
