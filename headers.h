#ifndef HEADERS_H
#define HEADERS_H

//declarar librerias
#include <iostream>
#include <list>
#include <vector>
#include <thread>

using namespace std;
//declarar clases
class Observer; //hace parte de la base 
class Subject; //es la base

class Guide; //guia el orden de los procesos

class Selection; //step1
class Routing; //step2
class Generation; //step3


#include "Observer.h"
#include "Subject.h"
#include "Guide.h"
#include "Selection.h"
#include "Routing.h"
#include "Generation.h"

#endif // HEADERS_H