#pragma once
#include <string>
#include <set>
#include <map>
#include <vector>

class Usuario;
class AdministraPropiedad;
class Inmobiliaria;
class Propietario;
class Suscriptor;
class Inmueble;
class Publicacion;
class DTNotificacion;
class DTPublicacion;
class DTUsuario;
class DTInmuebleAdministrado;
class DTInmuebleListado;

using String = std::string;

using SetSuscriptores = std::map<String, Suscriptor *>;

using SetInmobiliaria = std::map<std::string, Inmobiliaria *>;

using SetPropietario = std::map<std::string, Propietario *>;

using SetInmueble = std::map<int, Inmueble *>;

using SetPublicacion = std::map<int, Publicacion *>;

using SetDTNotificacion = std::vector<DTNotificacion *>;

using SetDTPublicacion = std::set<DTPublicacion *>;

using SetDTUsuario = std::set<DTUsuario *>;

using SetDTInmuebleAdministrado = std::set<DTInmuebleAdministrado *>;

using SetDTInmuebleListado = std::set<DTInmuebleListado *>;

using MapUsuario = std::map<std::string, Usuario *>;