#include "decorator.h"
#include <string>
#include <iostream>
#include "textprocess.h"
#include "dropfirst.h"


dropfirst::dropfirst(TextProcessor *comp, int num)
    : decorator {comp}, num{num}
    {}
// decorating a tp or a decorator


void dropfirst::setSource(std::istream *inp){
   tp->setSource(inp);
}

std::string dropfirst::getWord() {
    std::string s= tp->getWord();

    while (num >= s.length()){
        s= tp->getWord();
    }
    for (int i=0 ; i<num ; i++){
        s.replace(0,1,"");
    }

    return s;
}
