#ifndef _DROPFIRST_H_
#define _DROPFIRST_H_
#include "decorator.h"
#include <string>
class TextProcessor;

class dropfirst: public decorator {
    public: //constructors and methods
        dropfirst(TextProcessor *comp,  int num);

    void setSource(std::istream *inp) override;

    std::string getWord() override;

    protected:
    int num;
};
#endif
