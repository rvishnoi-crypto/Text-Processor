#ifndef _COUNT_H_
#define _COUNT_H_
#include "decorator.h"
#include <string>
class TextProcessor;

class count: public decorator {
    public: //constructors and methods
        count(TextProcessor *comp, char letter, int counter);

    void setSource(std::istream *inp) override;

    std::string getWord() override;

    protected:
    char c;
    int counter;
};
#endif
