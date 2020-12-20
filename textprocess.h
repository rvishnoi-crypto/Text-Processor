#ifndef __TEXTPROCESS_H__
#define __TEXTPROCESS_H__
#include <iostream>
#include <string>

struct DecoratorArgExn {
    std::string message; // details of the problem    
    DecoratorArgExn( std::string message );
}; 

// The abstract base class for the Decorator design pattern. Takes the role of the Component class
// from the UML class model for the Decorator design pattern. Provides the interface to implement.

class TextProcessor {
  public:
    // Passes the new input stream to use down the pipeline to the concrete component, Echo.
    virtual void setSource( std::istream *inp ) = 0;

    // Used to pass a request for another input word down the pipeline to the concrete component,
    // Echo. Returns a (possibly modified) word back up the pipeline to the main program, which
    // outputs it.
    virtual std::string getWord() = 0;

    // Destructor.
    virtual ~TextProcessor();
};

#endif
