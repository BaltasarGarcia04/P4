#ifndef SUSCRIPTOR_H
#define SUSCRIPTOR_H

#include "Dts/DTNotificacion.h"
#include <vector>
#include "Tipos.h"

class Suscriptor{
    private:
        SetDTNotificacion notificaciones;
    public:
        void Notificar(DTNotificacion* dt);
        void eliminarNotificaciones();
        SetDTNotificacion consultarNotificaciones();
        virtual ~Suscriptor();
};

#endif
