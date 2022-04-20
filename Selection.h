#ifndef SELECTION_H
#define SELECTION_H

#include "headers.h"

class Selection : public Observer{
    private:
        vector<Point> userPoints;
        vector<Point> selectedPoints;
    public:
        Selection();
        ~Selection(){}

        void setUserPoints(vector<Point>);
        vector<Point> getUserPoints();
        void process(void*);
        void obtainAllPoints();
        void obtainNodeInfo(xml_node<>* node);
        void analizePathChance(char* );
        void addPoint(string);
};

#endif // SELECTION_H