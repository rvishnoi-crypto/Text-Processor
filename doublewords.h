#ifndef _DOUBLE_H_
#define _DOUBLE_H_
#include "decorator.h"
#include <string>
class TextProcessor;

class doublewords: public decorator {
    public: //constructors and methods
    doublewords(TextProcessor *comp);
    
    void setSource(std::istream *inp) override;

    std::string getWord() override;

    protected:
    std::string prev_word;
    int prev_count;

};
#endif
