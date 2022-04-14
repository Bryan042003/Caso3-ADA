#ifndef ROUTING_H
#define ROUTING_H

#include "headers.h"

class Routing : public Observer{
    public:
        Routing();
        ~Routing(){}

        void process(void*);
};

#endif // ROUTING_H