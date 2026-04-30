#include "Dts/DTNotificacion.h"

DTNotificacion::DTNotificacion(
    String nicknameInmobiliria_,
    int codigoPublicacion_,
    String textoPublicacion_,
    TipoPublicacion tipoPublicacion_,
    TipoInmueble tipoInmueble_) 
    : 
    nicknameInmobiliria(nicknameInmobiliria_),
    codigoPublicacion(codigoPublicacion_),
    textoPublicacion(textoPublicacion_),
    tipoPublicacion(tipoPublicacion_),
    tipoInmueble(tipoInmueble_) 
    {};

DTNotificacion::DTNotificacion(DTNotificacion& dt)
    : 
    nicknameInmobiliria(dt.getNicknameInmobiliaria()),
    codigoPublicacion(dt.getCodigoPublicacion()),
    textoPublicacion(dt.getTextoPublicacion()),
    tipoPublicacion(dt.getTipoPublicacion()),
    tipoInmueble(dt.getTipoInmueble())
    {};

String DTNotificacion::getNicknameInmobiliaria() { return this->nicknameInmobiliria; };

int DTNotificacion::getCodigoPublicacion() { return this->codigoPublicacion; };

String DTNotificacion::getTextoPublicacion() { return this->textoPublicacion; };

TipoPublicacion DTNotificacion::getTipoPublicacion() { return this->tipoPublicacion; };

TipoInmueble DTNotificacion::getTipoInmueble() { return this->tipoInmueble; };

DTNotificacion::~DTNotificacion() {};
