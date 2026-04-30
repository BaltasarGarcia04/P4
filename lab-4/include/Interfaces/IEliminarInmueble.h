#ifndef IELIMINARINMUEBLE_H
#define IELIMINARINMUEBLE_H

#include "Dts/DTInmuebleListado.h"
#include "Dts/DTInmueble.h"
#include <set>
#include "Tipos.h"

class IEliminarInmueble
{
public:
    virtual SetDTInmuebleListado listarInmuebles() = 0;
    virtual DTInmueble *detalleInmueble(int codigoInmueble) = 0;
    virtual void eliminarInmueble(int codigoInmueble) = 0;
    virtual ~IEliminarInmueble() {};
};

#endif