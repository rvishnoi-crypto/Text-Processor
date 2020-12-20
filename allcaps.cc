#include <string>
#include "textprocess.h"
#include "allcaps.h"

allCaps::allCaps(TextProcessor *comp)
    : decorator{comp}
    //u have acess to parent methods as well as tp and source
    {}
// decorating a tp or a decorator

void allCaps::setSource(std::istream *inp){
    tp->setSource(inp);
// goes down the pipeline till echo object is found
}

std::string allCaps::getWord() { 
    std::string s= tp->getWord();
    std::string ans = s;
    int len = s.length();
    for (int i=0; i<=len-1; i++){
        if (ans[i]>= 97 && ans[i]<= 122){
            ans[i]=s[i]-32;
        }
        else{
            ans[i]=s[i];
        }
    }
    //using the source of the object
    return ans;
}

