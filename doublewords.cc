#include "decorator.h"
#include <string>
#include <iostream>
#include "textprocess.h"
#include "doublewords.h"


doublewords::doublewords(TextProcessor *comp)
    : decorator {comp}, prev_word{""}, prev_count{0}
    {}
// decorating a tp or a decorator


void doublewords::setSource(std::istream *inp){
   tp->setSource(inp);
}

std::string doublewords::getWord() {
    if (prev_word=="" || prev_count % 2==0){
        prev_count=0;
        prev_word= tp->getWord();
        prev_count++;
        return prev_word;
    }
    else {
        prev_count++;
        return prev_word;
    }
}
