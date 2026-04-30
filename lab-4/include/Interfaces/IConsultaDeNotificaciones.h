#ifndef ICONSULTADENOTIFICACIONES_H
#define ICONSULTADENOTIFICACIONES_H

#include "Dts/DTNotificacion.h"
#include <string>
#include <vector>
#include "Tipos.h"

class IConsultaDeNotificaciones {
    public: 
        virtual SetDTNotificacion consultarNotificaciones(String nicknameSuscriptor) = 0;
        virtual void eliminarNotificaciones() = 0;
        virtual ~IConsultaDeNotificaciones() {};
};

#endif