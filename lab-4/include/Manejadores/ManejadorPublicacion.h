#pragma once

#include <map>
#include <string>
#include "ManejadorUsuario.h"
#include "Clases/Propietario.h"
#include "Clases/AdministraPropiedad.h"
#include "Clases/Publicacion.h"
#include "Enums/TipoPublicacion.h"
#include "Dts/DTPublicacion.h"
#include "Dts/DTUsuario.h"
#include "Dts/DTInmuebleAdministrado.h"
#include "Controladores/ControladorFechaActual.h"
#include "Tipos.h"


class ManejadorPublicacion {
    private: 
        static ManejadorPublicacion* instancia;
        ManejadorPublicacion();
        
        int codigoUltimaPublicacion;
        SetPublicacion publicaciones;

        // No se si se utilizan esta dos, pero por las dudas las dejamos por ahora.
        void incrementarCodigoUltimaPublicacion();
        int getCodigoUltimaPublicacion();
        // -----------------------------------------------------------------------
    public:
        static ManejadorPublicacion* getInstance();
        Publicacion* crearPublicacion(AdministraPropiedad * ap, TipoPublicacion tipoPublicacion, std::string texto, float precio);
        SetPublicacion getpublicaciones();
        Publicacion* getPublicacion(int codigoPublicacion);
        SetDTPublicacion listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);
        SetDTUsuario listarInmobiliarias();
        SetDTInmuebleAdministrado *listarInmueblesAdministrados(String nicknameInmobiliaria);
        SetDTInmuebleAdministrado *listarInmueblesNoAdministrados(String nicknameInmobiliaria);
        ~ManejadorPublicacion();
};
