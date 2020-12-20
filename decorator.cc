#include "textprocess.h"
#include "decorator.h"

// Constructor 
decorator::decorator( TextProcessor *component )
  : tp{component}
{}
//set the source and the tp

// Destructor 
decorator::~decorator() { delete tp ;}


