#ifndef IELIMINARSUSCRIPCIONES
#define IELIMINARSUSCRIPCIONES

#include "Dts/DTInmobiliaria.h"
#include "Tipos.h"
class IEliminarSuscripciones {
    public:
        virtual SetDTInmobiliaria listarInmobiliariasSuscripto(String nicknameSuscriptor) = 0;
        virtual void eliminarSuscripcion(SetDTInmobiliaria DTInmobiliarias) = 0;
        virtual ~IEliminarSuscripciones() {};
};

#endif