#ifndef ICONSULTADEPUBLICACION_H
#define ICONSULTADEPUBLICACION_H

#include "Dts/DTPublicacion.h"
#include "Dts/DTInmueble.h"
#include "Enums/TipoPublicacion.h"
#include "Enums/TipoInmueble.h"
#include <set>
#include "Tipos.h"

class IConsultaDePublicacion {
    public:
        virtual SetDTPublicacion listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble) = 0;
        virtual DTInmueble* detalleInmueblePublicacion(int codigoPublicacion) = 0;
        virtual ~IConsultaDePublicacion() {};
};

#endif
