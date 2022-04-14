#ifndef SUBJECT_H
#define SUBJECT_H

#include "headers.h"

class Subject { //base
public:
  virtual ~Subject(){};
  virtual void attach(Observer *observer) = 0;
  virtual void detach(Observer *observer) = 0;
  virtual void produce(void*) = 0;
};

#endif // SUBJECT_H