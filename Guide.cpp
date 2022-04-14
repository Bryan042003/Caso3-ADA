#include "Guide.h"

Guide::Guide(){

}

void Guide::attach(Observer * step){
    steps.push_back(step);
}

void Guide::detach(Observer* step) {
    steps.erase(remove(steps.begin(), steps.end(), step), steps.end());
}

void Guide::produce(void* param) {
    int stepsSize = steps.size();
    for (int i = 0; i<stepsSize; i++){
        Observer * actual = steps.at(i);
        // actual->process(param);
        thread t(&Observer::process, actual, param);
        t.join();
    }
    // for (Observer* actual : estudiantes) {
    //     thread t(&Observer::update, actual, curso); // parametros = (direccionDeMetodo, instancia/objeto, parametro)
    //     t.join(); // espere a que t termine
    // }
}