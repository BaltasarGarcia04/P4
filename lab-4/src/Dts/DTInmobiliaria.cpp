#include "Dts/DTInmobiliaria.h"

DTInmobiliaria::DTInmobiliaria(String nombre_, String nickname_, String direccion_, String URL_, String telefono_) : nombre(nombre_), nickname(nickname_), direccion(direccion_), URL(URL_), telefono(telefono_) {};

String DTInmobiliaria::getNombre() { return this->nombre; };

String DTInmobiliaria::getNickname() { return this->nickname; };

String DTInmobiliaria::getDireccion() { return this->direccion; };

String DTInmobiliaria::getURL() { return this->URL; };

String DTInmobiliaria::getTelefono() { return this->telefono; };

void toString() {};

DTInmobiliaria::~DTInmobiliaria() {};