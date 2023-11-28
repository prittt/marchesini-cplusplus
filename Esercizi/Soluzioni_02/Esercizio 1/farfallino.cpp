#include "farfallino.h"

std::string CodificaFarfallino(const std::string& input) {
    std::string codificata;
    for (char c: input) {
        switch (c) {
        break; case 'a': codificata += "afa";
        break; case 'e': codificata += "efe";
        break; case 'i': codificata += "ifi";
        break; case 'o': codificata += "ofo";
        break; case 'u': codificata += "ufu";
        break; default:  codificata += c;
        }
    }
   return codificata;
}
