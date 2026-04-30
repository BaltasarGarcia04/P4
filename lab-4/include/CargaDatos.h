#ifndef CARGADATOS_H
#define CARGADATOS_H

#include "Factory/Factory.h"

class CargaDatos {
    private:
        static CargaDatos* instance;
        CargaDatos();

    public:
        static CargaDatos* getInstance();
        ~CargaDatos();
};

#endif