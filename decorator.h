#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "textprocess.h"

// This is the decorator which is also a text processor
class decorator: public TextProcessor {
    protected:
    TextProcessor *tp; // this points to the text processor
    
    public:
    decorator(TextProcessor *component);
    virtual ~decorator(); //since decorator is derived from abstract class  
};
#endif
