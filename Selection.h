#ifndef SELECTION_H
#define SELECTION_H

#include "headers.h"

class Selection : public Observer{
    public:
        Selection();
        ~Selection(){}

        void process(void*);
};

#endif // SELECTION_H