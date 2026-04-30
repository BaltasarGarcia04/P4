#ifndef ISUSCRIBIRSEANOTIFICACIONES_H
#define ISUSCRIBIRSEANOTIFICACIONES_H

#include "Dts/DTInmobiliaria.h"
#include "Tipos.h"
class ISuscribirseANotificaciones
{
public:
    virtual SetDTInmobiliaria listarInmobiliariasNoSuscripto(String nicknameSuscriptor) = 0;
    virtual void suscribirAInmobiliaria(std::string nicknameUsuario, SetString setNicknameInmobiliarias) = 0;
    virtual ~ISuscribirseANotificaciones() {};
};

#endif