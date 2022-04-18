#ifndef EXTRACTSVG_H
#define EXTRACTSVG_H

#include "headers.h"

class ExtractSVG{
    //puntero al arbol
    private:
        string fileName;
        xml_document<> * dom;

    public:
        ExtractSVG(string);

        void extractXMLData();
        void extractNodeData(xml_node<>* node);
        void extractFullSVG();
        xml_document<> * getDom();
};

#endif // EXTRACTSVG_H
