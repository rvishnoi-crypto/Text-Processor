#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "textprocess.h"
#include "echo.h"
#include "decorator.h"
#include "allcaps.h"
#include "count.h"
#include "dropfirst.h"
#include "doublewords.h"

// Add includes for your own decorator classes

int main () {
    istream *in = nullptr;

    // Turns on the raising of exceptions when the fail or the eof bit get set for std::cin.
    cin.exceptions( ios::failbit|ios::eofbit );
    string s;

    try {
        // Process each command from std::cin until we run out.
        while ( getline( cin, s ) ) {
            // Declare these outside the try-catch block so that they're available after the catch.
            TextProcessor *tp = nullptr;

            try {
                istringstream iss{s};
                iss.exceptions( ios::failbit ); // raise exception if fails
                string fname;
                iss >> fname;
                if ( fname == "stdin" ) { 
                    in = &cin; 
                } else {
                    in = new ifstream{ fname };
                    if ( in->fail() ) {
                        std::cerr << "Unable to open file " << fname << std::endl;
                        delete in;
                        in = nullptr;
                        break;
                    } // if
                } // if

                // Turns on the raising of exceptions when the fail or the eof bit get set for "in".
                in->exceptions( ios::failbit | ios::eofbit );

                // Pipeline starts with the concrete component, an Echo object instance.
                tp = new Echo{};

                // Build up the pipeline of decoration objects, adding each one to the front of the
                // pipeline in turn. Stop when the istringstream runs out of input.
                try {
                    string dec;
                    while ( iss >> dec ) {
                        if ( dec == "dropfirst" ) {
                            int n;
                            iss >> n;
                            // *** Create the appropriate object and link it into the pipeline.
                            // *** You will need to be be careful how you do this so that you neither
                            // *** leak memory nor free memory twice.
                            if (n>=0){
                                tp = new dropfirst{tp,n} ;
                            }
                            else{
                                throw DecoratorArgExn{"ERROR: DropFirst: n < 0"};
                                
                            }
                                

                        } else if ( dec == "doublewords" ) {
                            // *** Create the appropriate object and link it into the pipeline.
                            tp = new doublewords{tp} ;

                        } else if ( dec == "allcaps" ) {
                            // *** Create the appropriate object and link it into the pipeline.
                            tp = new allCaps{tp};
                        } else if ( dec == "count" ) {
                            char c;
                            iss >> c;
                            // *** Create the appropriate object and link it into the pipeline.
                            tp = new count{tp,c,0} ;
                        } // if
                    } // while
                } catch (ios::failure) {} 

                // Pass the input source down the pipeline to the concrete component.
                tp->setSource( in );

                // Process the input from the new source until we run out. Number each line as we go.
                try {
                    string word;
                    int lineNum = 1;
                    while (true) {
                        word = tp->getWord();
                        cout << lineNum++ << ' ' << word << endl;
                    } // while
                } catch (ios::failure) {}

            } catch ( DecoratorArgExn & e ) {
                cerr << e.message << endl;
            } // catch
                 
            if (in != &cin) delete in;
            delete tp; // clean up the pipeline

        } // while
    } catch (ios::failure) {}
} // main
