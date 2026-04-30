#ifndef CONTROLADORINMUEBLE_H
#define CONTROLADORINMUEBLE_H

#include "Interfaces/IEliminarInmueble.h"
#include "Manejadores/ManejadorUsuario.h"
class ControladorInmueble : public IEliminarInmueble
{
private:
    static ControladorInmueble *instance;
    ControladorInmueble();

public:
    static ControladorInmueble *getInstance();

    // Realización interfaz IEliminarInmueble
    SetDTInmuebleListado listarInmuebles();
    DTInmueble *detalleInmueble(int codigoInmueble);
    void eliminarInmueble(int codigoInmueble);
    ~ControladorInmueble();
};

#endif