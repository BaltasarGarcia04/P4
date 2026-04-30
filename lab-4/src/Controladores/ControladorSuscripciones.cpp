#include "Controladores/ControladorSuscripciones.h"
#include "Manejadores/ManejadorUsuario.h"
#include "Clases/Inmobiliaria.h"
#include "Clases/Suscriptor.h"
#include "Dts/DTInmobiliaria.h"
#include <iostream>

ControladorSuscripciones *ControladorSuscripciones::instance = nullptr;

ControladorSuscripciones::ControladorSuscripciones() {}

ControladorSuscripciones *ControladorSuscripciones::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorSuscripciones();
    }
    return instance;
}

SetDTInmobiliaria ControladorSuscripciones::listarInmobiliariasNoSuscripto(String nicknameSuscriptor)
{
    // Obtengo instancia de ManejadorUsuario.
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();

    Suscriptor *sus_ = manejadorUsuario->getSuscriptor(nicknameSuscriptor);

    if (sus_ != nullptr)
    {
        this->sus = sus_;
    }
    else
    {
        std::cout << "No existe instancia de Suscriptor" << std::endl;
    }

    // Obtengo Set de inmobiliarias en el sistema.
    std::set<Inmobiliaria *> inmobiliarias = manejadorUsuario->getInmobiliarias();

    // Declaro Set de DTInmobiliaria a retornar posteriormente.
    SetDTInmobiliaria DTInmobiliarias;

    // Itero sobre Set de inmobiliarias.
    for (std::set<Inmobiliaria *>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it)
    {
        Inmobiliaria *inmobiliaria = *it;

        // Verifico si nicknameSuscriptor es
        bool esSub = inmobiliaria->esSuscriptor(this->sus);

        // Si nicknameSuscriptor no es Suscriptor de inmobiliaria, añado DTInmobiliaria a Set DTInmobiliaria.
        if (!esSub)
        {
            DTInmobiliaria *dtin = inmobiliaria->getDT();
            DTInmobiliarias.insert(dtin);
        }
    }

    // Retorno Set inmobiliarias que nicknameSuscriptor no está suscripto.
    return DTInmobiliarias;
};

void ControladorSuscripciones::suscribirAInmobiliaria(std::string nicknameUsuario, SetString setNicknameInmobiliarias)
{
    // Obtengo instancia de ManejadorUsuario.
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();
    Suscriptor *suscriptor = manejadorUsuario->getSuscriptor(nicknameUsuario);
    // Obtengo cada instancia de nicknameInmobiliaria en Set pasado por parámetro y añado como suscriptor this->sus.
    for (SetString::iterator it = setNicknameInmobiliarias.begin(); it != setNicknameInmobiliarias.end(); ++it)
    {
        String nicknameInmobiliaria = *it;
        Inmobiliaria *i = manejadorUsuario->getInmobiliaria(*it);
        i->agregarSuscriptor(suscriptor);
    }

    // Limpio this->sus.
    // this->sus = nullptr;
};

SetDTNotificacion ControladorSuscripciones::consultarNotificaciones(String nicknameSuscriptor)
{
    // Obtengo instancia de ManejadorUsuario.
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();

    // Declaro Set de DTNotificacion a retornar posteriormente.
    SetDTNotificacion DTNotificaciones;

    // Obtengo instancia de Suscriptor con nicknameSuscriptor.
    Suscriptor *sus_ = manejadorUsuario->getSuscriptor(nicknameSuscriptor);

    if (sus_ != nullptr)
    {
        this->sus = sus_;
    }
    else
    {
        std::cout << "No existe instancia de Suscriptor" << std::endl;
    }

    DTNotificaciones = this->sus->consultarNotificaciones();

    return DTNotificaciones;
}

void ControladorSuscripciones::eliminarNotificaciones()
{
    // Elimino notificaciones de this->sus.
    this->sus->eliminarNotificaciones();

    // Limpio this->sus.
    this->sus = nullptr;
}

SetDTInmobiliaria ControladorSuscripciones::listarInmobiliariasSuscripto(String nicknameSuscriptor)
{
    // Obtengo instancia de ManejadorUsuario.
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();

    SetDTInmobiliaria DTInmobiliarias;

    // Obtengo instancia de suscriptor nicknameSuscriptor.
    Suscriptor *sus_ = manejadorUsuario->getSuscriptor(nicknameSuscriptor);

    if (sus_ != nullptr)
    {
        this->sus = sus_;
    }
    else
    {
        std::cout << "No existe instancia de Suscriptor" << std::endl;
    }

    // Obtengo set de inmobiliarias en el sistema.
    std::set<Inmobiliaria *> setInmobiliarias = manejadorUsuario->getInmobiliarias();

    for (std::set<Inmobiliaria *>::iterator it = setInmobiliarias.begin(); it != setInmobiliarias.end(); ++it)
    {
        Inmobiliaria *inmobiliaria = *it;

        bool esSub = inmobiliaria->esSuscriptor(this->sus);

        if (esSub)
        {
            DTInmobiliaria *dtIn = inmobiliaria->getDT();
            DTInmobiliarias.insert(dtIn);
        }
    }

    return DTInmobiliarias;
}

void ControladorSuscripciones::eliminarSuscripcion(SetDTInmobiliaria DTInmobiliarias)
{
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();

    for (SetDTInmobiliaria::iterator it = DTInmobiliarias.begin(); it != DTInmobiliarias.end(); ++it)
    {
        DTInmobiliaria *dti = *it;

        String nicknameInmobiliaria = dti->getNickname();

        Inmobiliaria *i = manejadorUsuario->getInmobiliaria(nicknameInmobiliaria);

        i->eliminarSuscriptor(this->sus);
    }

    this->sus = nullptr;
}

ControladorSuscripciones::~ControladorSuscripciones() {}