#include "decorator.h"
#include <string>
#include <iostream>
#include "textprocess.h"
#include "count.h"


count::count(TextProcessor *comp, char letter, int counter)
    : decorator {comp}, c{letter}, counter{0}
    {}
// decorating a tp or a decorator


void count::setSource(std::istream *inp){
   tp->setSource(inp);
}

std::string count::getWord() {
    std::string s= tp->getWord(); 
    for (int i=0; i <= s.length()-1; i++){
        if (s[i]==c){
            counter++;
            s.replace(i,1,std::to_string(counter));
        } 
    }
    return s;
}

