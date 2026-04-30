#ifndef IALTAUSUARIO_H
#define IALTAUSUARIO_H

#include "Dts/DTInmuebleAdministrado.h"
#include "Dts/DTUsuario.h"
#include "Enums/TipoPublicacion.h"
#include <string>
#include <set>
#include "Tipos.h"

class IAltaPublicacion {
    public:
        virtual SetDTInmuebleAdministrado listarInmueblesAdministrados(String nicknameInmobiliaria) = 0;
        virtual SetDTUsuario listarInmobiliarias() = 0;
        virtual bool altaPublicacion(String nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, String texto, float precio) = 0;
        virtual ~IAltaPublicacion() {};
};

#endif