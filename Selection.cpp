#include "Selection.h"

Selection::Selection(){
}
void Selection::setUserPoints(vector<Point> points){
    this->userPoints = points;
}
vector<Point> Selection::getUserPoints(){
    return this->userPoints;
}

void Selection::process(void*param){
    obtainAllPoints();
}

void Selection::obtainAllPoints(){
    xml_node<>* node = getDom()->first_node();
    obtainNodeInfo(node); //sends dom root
}

void Selection::obtainNodeInfo(xml_node<>* node){
    for (node = node->first_node(); node != NULL; node = node->next_sibling()){ //goes through nodes of dom (every path,g, or whatever bracket)
        if (node->type() == node_element){ 
            //cout << "Etiqueta: " << node->name() << endl;
            if(strcmp(node->name(),"path")==0){ //if the node is a path goes in
                for (xml_attribute<>* attrib = node->first_attribute(); attrib != NULL; attrib = attrib->next_attribute()){//goes through every attribute at path such as d, stroke, etc
                    if (strcmp(attrib->name(),"d")==0){ //if the attribute is at is a d goes in
                        analizePathChance(attrib->value()); //inserts the value inside d
                    }
                }
            }
            obtainNodeInfo(node);
        }
   }
}
bool isCharNeeded(char character){
    return character=='M'||character=='L'||character=='H'||character=='V';
}
bool isDigit(char character){
    if (character==45||character==46||character==32||character==44) //if '-' || '.' || ',' || ' '
        return true;
    return isdigit(character);
}

void Selection::addPoint(string pointInfo){
    //must create the point here, validating all possibilities like white spaces or not white spaces and commas
}

void Selection::analizePathChance(char* info){
    vector<Point>pathPoints; //insert all the points made from the data
    int infoLength = strlen(info); //amount of characters from data info in each path
    for (int i=0; i<infoLength; i++){ //goes trough "d" info
        if (isCharNeeded(toupper(info[i]))){ //values if the char is either M,L,H,V (converts to upper to make it easier)
            int countAttribute = i+1; //for counting the atributte
            string infoAttribute = "";
            while(isDigit(info[countAttribute])) //while is inside the info of a point
            {
                infoAttribute+=info[countAttribute];
                countAttribute++;
                i++; //has to be incremented here 'cause we are still going through the char[]
            }
            cout << infoAttribute << endl;
            addPoint(infoAttribute); //makes the point
        }
    }
}
