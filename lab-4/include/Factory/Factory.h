#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "Interfaces/IAltaDeUsuario.h"
#include "Interfaces/IAltaPublicacion.h"
#include "Interfaces/IConsultaDeNotificaciones.h"
#include "Interfaces/IConsultaDePublicacion.h"
#include "Interfaces/IEliminarInmueble.h"
#include "Interfaces/IEliminarSuscripciones.h"
#include "Interfaces/ISuscribirseANotificaciones.h"
#include "Interfaces/IAltaDeAdministracioDePropiedad.h"

class Factory
{
private:
    static Factory *instance;
    Factory();

public:
    static Factory *getInstance();
    IControladorFechaActual *getControladorFechaActual();
    IAltaDeAdministracionDePropiedad *getControladorPublicacionAP();
    IAltaDeUsuario *getControladorUsuario();
    IAltaPublicacion *getControladorPublicacion();
    IConsultaDeNotificaciones *getControladorSuscripciones();
    IConsultaDePublicacion *getControladorPublicacionConsulta();
    IEliminarInmueble *getControladorInmueble();
    IEliminarSuscripciones *getControladorSuscripcionesEliminar();
    ISuscribirseANotificaciones *getControladorSuscripcionesSuscribirse();
    ~Factory();
};

#endif