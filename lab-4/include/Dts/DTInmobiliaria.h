#ifndef DTINMOBILIARIA
#define DTINMOBILIARIA

#include <string>
#include <set>

class DTInmobiliaria;

using SetDTInmobiliaria = std::set<DTInmobiliaria*>;
using SetString = std::set<std::string>;
using String = std::string;

class DTInmobiliaria {
    private:
        String nombre;
        String nickname;
        String direccion;
        String URL;
        String telefono;
    public:
        DTInmobiliaria(String nombre_, String nickname_, String direccion_, String URL_, String telefono_);
        String getNombre();
        String getNickname();
        String getDireccion();
        String getURL();
        String getTelefono();
        void toString();
        ~DTInmobiliaria();
};

#endif
