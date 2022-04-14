#ifndef OBSERVER_H
#define OBSERVER_H

#include "headers.h"

class Observer { //hace parte de la base 
public:
  virtual ~Observer(){};
  virtual void process(void*) = 0;
};

#endif // OBSERVER_H