#include "headers.h"



int main(){
    string fileName = "sample.svg";
    ExtractSVG * svg = new ExtractSVG(fileName);
    svg->extractFullSVG();
    svg->getDom();
    
    Observer* selection = new Selection();
    Observer* routing = new Routing();
    Observer* generation = new Generation();
    selection->setDom(svg->getDom());
    routing->setDom(svg->getDom());    
    generation->setDom(svg->getDom());  

   Subject* guide = new Guide();
   guide->attach(selection);
   guide->attach(routing);
   guide->attach(generation);

   int num = 3;
   int* numPointer = &num;
   guide->produce(numPointer);
  

   //svg->extractXMLData();

  return 0;
}
// int main(){
//    Observer* selection = new Selection();
//    Observer* routing = new Routing();
//    Observer* generation = new Generation();

//    Subject* guide = new Guide();
//    guide->attach(selection);
//    guide->attach(routing);
//    guide->attach(generation);

//    int num = 3;
//    int* numPointer = &num;
//    guide->produce(numPointer);


//     return 0;
// }