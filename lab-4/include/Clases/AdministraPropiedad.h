#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "Dts/DTFecha.h"
#include "Dts/DTPublicacion.h"
#include "Dts/DTInmueble.h"
#include "Clases/Inmueble.h"
#include "Clases/Inmobiliaria.h"
#include "Controladores/ControladorFechaActual.h"
#include "Clases/Publicacion.h"
#include <set>
#include <string>

class Publicacion;

class AdministraPropiedad {
    private:
        DTFecha* fecha;
        Inmueble* inmueble;
        Inmobiliaria* inmobiliaria;
        std::set<Publicacion*> inactivas;
        //en activas el indice 0 es para la publicacion de tipo alquiler 
        //el indice 1 es para la publicacion de tipo venta
        Publicacion* activas[2];

    public:
    //constructores
        AdministraPropiedad(DTFecha* fecha, Inmueble* inmueble, Inmobiliaria* inmobiliaria);

    //getters estandars
        DTFecha* getDTfecha();

    // getters indirectos 
        TipoInmueble getTipoinmueble();
        std::string getNicknameInmobiliaria();
        String getNombreInmobiliaria();
        int getCodigoInmueble();
        std::string getDireccionInmobiliaria();
        std::string getDireccionInmueble();
        DTInmueble* getDTInmueble();
        
    //funciones de coleccion
        void agregarPublicacion(Publicacion* p);
        void eliminarPublicacion(Publicacion* p);
        bool existePublicacionActiva(DTFecha* Fecha,TipoPublicacion tipoPublicacion);
        Publicacion* getPublicacionActiva(TipoPublicacion tipoPublicacion); 
        DTPublicacion getDTPublicacionActiva(TipoPublicacion tipoPublicacion);
    //destructor
        ~AdministraPropiedad();
};

#endif
