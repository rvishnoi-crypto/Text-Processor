#ifndef _ALLCAPS_H_
#define _ALLCAPS_H_
#include "decorator.h"
#include <string>
class TextProcessor;

//child of the decorator 
class allCaps: public decorator {
    public: //constructors and methods
    allCaps(TextProcessor *comp);
    
    void setSource(std::istream *inp) override;

    std::string getWord() override;

};
#endif
