#include "headers.h"

int main(){
    /*
    Observer* est1 = new Estudiante();
    Observer* est2 = new Estudiante();
    Observer* est3 = new Estudiante();

    Subject* plat = new Plataforma();
    plat->attach(est1);
    plat->attach(est2);
    plat->attach(est3);

    int curso = 2;
    int* cursoPointer = &curso;
    plat->notify(cursoPointer);

    cout << endl;
    cout << "Estudiante 1 ha abandonado un curso" << endl;
    plat->detach(est1);
    cout << "Vamos a crear una tarea nueva" << endl;
    curso = 1;
    plat->notify(cursoPointer);

    */

   Observer* selection = new Selection();
   Observer* routing = new Routing();
   Observer* generation = new Generation();

   Subject* guide = new Guide();
   guide->attach(selection);
   guide->attach(routing);
   guide->attach(generation);

   int num = 3;
   int* numPointer = &num;
   guide->produce(numPointer);


    return 0;
}