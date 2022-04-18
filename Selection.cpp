#include "Selection.h"

Selection::Selection(){
    
}
void Selection::setPoints(vector<Point> points){
    this->points = points;
}
vector<Point> Selection::getPoint(){
    return this->points;
}

void Selection::process(void*param){
    obtainAllPoints();
}

void Selection::obtainAllPoints(){
    xml_node<>* node = getDom()->first_node();

    // cout << "Etiqueta: " << node->name() << endl;

    // for (xml_attribute<>* attrib = node->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){
    //     cout <<"hola"<<endl;
    //     cout << " Atributo: " << attrib->name() << endl;
    //     cout << "\tValor: " << attrib->value() << endl;
    // }
    obtainNodeInfo(node);
}


void Selection::obtainNodeInfo(xml_node<>* node){
    for (node = node->first_node(); node != NULL; node = node->next_sibling()){
        if (node->type() == node_element){
            //cout << "Etiqueta: " << node->name() << endl;
            if(strcmp(node->name(),"path")==0){
                for (xml_attribute<>* attrib = node->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){
                    if (strcmp(attrib->name(),"d")==0){
                        cout << attrib->value() << endl;
                    }
                }
            }
            obtainNodeInfo(node);
        }
   }
}