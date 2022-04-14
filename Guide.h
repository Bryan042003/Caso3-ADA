#ifndef GUIDE_H
#define GUIDE_H

#include "headers.h"

class Guide : public Subject{
    private:
        vector<Observer*> steps;
    public:
        Guide();
        ~Guide(){}

        void attach(Observer*);
        void detach(Observer*);
        void produce(void*);
};

#endif // GUIDE_H