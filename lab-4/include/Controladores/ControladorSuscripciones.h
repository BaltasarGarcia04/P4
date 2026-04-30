#ifndef CONTROLADORSUSCRIPCIONES
#define CONTROLADORSUSCRIPCIONES

#include "Interfaces/ISuscribirseANotificaciones.h"
#include "Interfaces/IConsultaDeNotificaciones.h"
#include "Interfaces/IEliminarSuscripciones.h"
#include "Clases/Suscriptor.h"
#include "Tipos.h"
#include <iostream>

class ControladorSuscripciones : public ISuscribirseANotificaciones, public IConsultaDeNotificaciones, public IEliminarSuscripciones
{
private:
    static ControladorSuscripciones *instance;
    ControladorSuscripciones();
    Suscriptor *sus;

public:
    // Instancia ControladorSuscripciones
    static ControladorSuscripciones *getInstance();

    // Realización de ISuscribirseANotificaciones
    SetDTInmobiliaria listarInmobiliariasNoSuscripto(String nicknameSuscriptor) override;
    void suscribirAInmobiliaria(std::string nicknameUsuario, SetString setNicknameInmobiliarias) override;

    // Realizacion de IConsultaDeNotificaciones
    SetDTNotificacion consultarNotificaciones(String nicknameSuscriptor) override;
    void eliminarNotificaciones() override;

    // Realizacion de IEliminarSuscripciones
    SetDTInmobiliaria listarInmobiliariasSuscripto(String nicknameSuscriptor) override;
    void eliminarSuscripcion(SetDTInmobiliaria DTInmobiliarias) override;

    ~ControladorSuscripciones();
};

#endif