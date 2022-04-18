#include "ExtractSVG.h"

ExtractSVG::ExtractSVG(string fileName){
    this->fileName = fileName;
}

xml_document<> * ExtractSVG::getDom(){
    return this->dom;
}

void ExtractSVG::extractXMLData(){
    xml_node<>* node = this->dom->first_node();

    cout << "Etiqueta: " << node->name() << endl;
    for (xml_attribute<>* attrib = node->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){
        cout << " Atributo: " << attrib->name() << endl;
        cout << "\tValor: " << attrib->value() << endl;
    }

    extractNodeData(node);
}

void ExtractSVG::extractNodeData(xml_node<>* node){
    for (node = node->first_node(); node != NULL; node = node->next_sibling()){
    if (node->type() == node_element){
      cout << "Etiqueta: " << node->name() << endl;

      for (xml_attribute<>* attrib = node->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){
        cout << "\tAtributo: " << attrib->name() << endl;
        cout << "\t-Valor: " << attrib->value() << endl;
      }

      extractNodeData(node);
    }
  }

}

void ExtractSVG::extractFullSVG(){

    const char* fileCaseName = this->fileName.c_str();

    //Leer XML
    file<> file(fileCaseName); // Lee y carga el archivo en memoria
    xml_document<> myDoc; //Raíz del árbol DOM
    myDoc.parse<0>(file.data()); //Parsea el XML en un DOM

    this->dom = &myDoc;

    // //Recorrer elementos y atributos
    //extractXMLData();

    // //Modificar un atributo existente
    // //Modifica el atributo indicado del primer elemento <path> que se encuentre
    // xml_node<> *modifyNode = myDoc.first_node()->first_node("path");

    // string newDirection = "M 10 10 L 50 50 L 10 50 Z";
    // modifyNode->first_attribute("d")->value(newDirection.c_str());

    // string newColor = "pink";
    // modifyNode->first_attribute("stroke")->value(newColor.c_str());

    // modifyNode->next_sibling("g")->first_attribute("stroke")->value(newColor.c_str());

    // //Insertar un nuevo elemento
    // xml_node<> *newNode = myDoc.allocate_node(node_element, "path");
    // myDoc.first_node()->append_node(newNode); //Elemento <path>

    // xml_attribute<> *newAttr = myDoc.allocate_attribute("d", "M 0 0 L 0 15 L 20 15 L 20 20 Z");
    // newNode->append_attribute(newAttr); //Atributo "d" para <path>

    // xml_attribute<> *newAttr2 = myDoc.allocate_attribute("fill", "green");
    // newNode->append_attribute(newAttr2); //Atributo "fill" para <path>

    // //Escribir un nuevo archivo
    // ofstream copyFile("sample2.svg"); //Nuevo archivo
    // stringstream ss;
    // ss << *myDoc.first_node(); //Pasa el nodo raíz a ss
    // string stringXML = ss.str(); //ss.toString
    // copyFile << stringXML;
    // copyFile.close(); //Escribe y cierra

    // //Document to String
    // string strXML;
    // print(back_inserter(strXML), myDoc, 0); //Copia el texto del Document en la variable
    // cout << strXML << endl;

}