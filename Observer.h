#ifndef OBSERVER_H
#define OBSERVER_H

#include "headers.h"

class Observer { //hace parte de la base
private:
  xml_document<> * dom;
public:
  virtual ~Observer(){};
  virtual void process(void*) = 0;

  void setDom(xml_document<>* dom){
    this->dom = dom;
  }
  xml_document<> * getDom(){
    return this->dom;
  }
  
};

#endif // OBSERVER_H