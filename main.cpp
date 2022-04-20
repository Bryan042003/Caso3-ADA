#include "headers.h"



int main(){
    string fileName = "sample.svg";
    ExtractSVG * svg = new ExtractSVG(fileName);
    svg->extractFullSVG(); //parses svg into and xml
    
    Observer* selection = new Selection();
    Observer* routing = new Routing();
    Observer* generation = new Generation();
    //sends the dom to each process
    selection->setDom(svg->getDom());
    routing->setDom(svg->getDom());    
    generation->setDom(svg->getDom());

    Subject* guide = new Guide();//platform
    guide->attach(selection);
    guide->attach(routing);
    guide->attach(generation);

    int num = 3;
    int* numPointer = &num;
    guide->produce(numPointer);
  

   //svg->extractXMLData(); //print svg arbol

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