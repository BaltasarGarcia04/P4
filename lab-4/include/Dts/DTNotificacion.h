#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include "Enums/TipoPublicacion.h"
#include "Enums/TipoInmueble.h"
#include "Tipos.h"

class DTNotificacion {
    private:
        String nicknameInmobiliria;
        int codigoPublicacion;
        String textoPublicacion;
        TipoPublicacion tipoPublicacion;
        TipoInmueble tipoInmueble;
    public:
        DTNotificacion(
            String nicknameInmobiliria_,
            int codigoPublicacion_,
            String textoPublicacion_,
            TipoPublicacion tipoPublicacion_,
            TipoInmueble tipoInmueble_);
        DTNotificacion(DTNotificacion& dtn);
        String getNicknameInmobiliaria();
        int getCodigoPublicacion();
        String getTextoPublicacion();
        TipoPublicacion getTipoPublicacion();
        TipoInmueble getTipoInmueble();

        ~DTNotificacion();
};

#endif
