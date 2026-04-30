#include "Factory/Factory.h"
#include "Controladores/ControladorFechaActual.h"
#include "Controladores/ControladorUsuario.h"
#include "Controladores/ControladorPublicacion.h"
#include "Controladores/ControladorSuscripciones.h"
#include "Controladores/ControladorInmueble.h"
#include <cstddef>

Factory *Factory::instance = NULL;

Factory::Factory()
{
}

Factory *Factory::getInstance()
{
    if (instance == NULL)
    {
        instance = new Factory();
    }
    return instance;
}

IControladorFechaActual *Factory::getControladorFechaActual()
{
    return ControladorFechaActual::getInstance();
}

IAltaDeUsuario *Factory::getControladorUsuario()
{
    return ControladorUsuario::getInstance();
}

IAltaPublicacion *Factory::getControladorPublicacion()
{
    return ControladorPublicacion::getInstance();
}
IAltaDeAdministracionDePropiedad *Factory::getControladorPublicacionAP()
{
    return ControladorPublicacion::getInstance();
}

IConsultaDeNotificaciones *Factory::getControladorSuscripciones()
{
    return ControladorSuscripciones::getInstance();
}
IConsultaDePublicacion *Factory::getControladorPublicacionConsulta()
{
    return ControladorPublicacion::getInstance();
}
IEliminarInmueble *Factory::getControladorInmueble()
{
    return ControladorInmueble::getInstance();
}
IEliminarSuscripciones *Factory::getControladorSuscripcionesEliminar()
{
    return ControladorSuscripciones::getInstance();
}

ISuscribirseANotificaciones *Factory::getControladorSuscripcionesSuscribirse()
{
    return ControladorSuscripciones::getInstance();
}