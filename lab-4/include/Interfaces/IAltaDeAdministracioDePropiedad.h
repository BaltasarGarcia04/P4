#ifndef IALTADEADMINISTRACIONDEPROPIEDAD_H
#define IALTADEADMINISTRACIONDEPROPIEDAD_H

#include "Dts/DTUsuario.h"
#include "Dts/DTInmuebleListado.h"
#include <set>
#include <string>
#include "Tipos.h"

class IAltaDeAdministracionDePropiedad
{
public:
    virtual SetDTUsuario listarInmobiliarias() = 0;
    virtual SetDTInmuebleListado listarInmueblesNoAdministradosInmobiliaria(String nicknameInmobiliaria) = 0;
    virtual void altaAdministraPropiedad(String nicknameInmobiliaria, int codigoInmueble) = 0;
    virtual ~IAltaDeAdministracionDePropiedad() {};
};

#endif