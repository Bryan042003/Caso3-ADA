#ifndef HEADERS_H
#define HEADERS_H

//declarar librerias
#include <iostream>
#include <list>
#include <vector>
#include <thread>
#include "rapidxml/rapidxml_ext.hpp" //Clases para manejo del DOM
#include "rapidxml/rapidxml_utils.hpp" //Clase File
#include <sstream>
#include <fstream>
//#include <string>

using namespace std;
using namespace rapidxml; //Namespace de la librería

//declarar clases
class ExtractSVG;
class Point;

class Observer; //hace parte de la base 
class Subject; //es la base

class Guide; //guia el orden de los procesos

class Selection; //step1
class Routing; //step2
class Generation; //step3

#include "Point.h"
#include "Observer.h"
#include "Subject.h"
#include "Guide.h"
#include "Selection.h"
#include "Routing.h"
#include "Generation.h"
#include "ExtractSVG.h"

#endif // HEADERS_H