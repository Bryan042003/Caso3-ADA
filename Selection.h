#ifndef SELECTION_H
#define SELECTION_H

#include "headers.h"

class Selection : public Observer{
    private:
        vector<Point> points;
    public:
        Selection();
        ~Selection(){}

        void setPoints(vector<Point>);
        vector<Point> getPoint();
        void process(void*);
        void obtainAllPoints();
        void obtainNodeInfo(xml_node<>* node);
};

#endif // SELECTION_H