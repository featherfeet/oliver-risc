#include "util.h"

bool isRegister(std::string identifier) {
    return identifier == "IP" || identifier == "A" || identifier == "B" || identifier == "C" || identifier == "D" || identifier == "E" || identifier == "F" || identifier == "G" || identifier == "IE" || identifier == "IR";
}
