#ifndef GENERATION_H
#define GENERATION_H

#include "headers.h"

class Generation : public Observer{
    public:
        Generation();
        ~Generation(){}

        void process(void*);
};

#endif // GENERATION_H