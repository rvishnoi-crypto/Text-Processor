#include <iostream>
#include <string>
#include "echo.h"

Echo::Echo(): source{nullptr} {}

void Echo::setSource( std::istream *in ) { source = in; }

std::string Echo::getWord() {
    std::string s;
    *source >> s;
    return s;
}
