#include "Andar.hpp"

int Andar::_num_andares = 0;

Andar::Andar()
{
    _num = _num_andares++;
    _estado = SEM_PEDIDO;
}
Andar::~Andar()
{
    _num_andares--;
}

enum ESTADOS_ANDAR Andar::estado_andar()
{
    return _estado;
}


void Andar::atendeuAndar()
{
    _estado = SEM_PEDIDO;
}

/*---------------------------------------------------------//
* estado_andar WIP
//---------------------------------------------------------*/
void Andar::pedidoSubida()
{
    switch (_estado)
    {
        case SEM_PEDIDO:
            _estado = PEDIDO_SUBIDA;
            filaChamadasOrigem.push(_num);
            break;
        case PEDIDO_DESCIDA:
            _estado = PEDIDO_DESTINO;
            break;
        default:
            break;
    }
}

/*---------------------------------------------------------//
* estado_andar WIP
//---------------------------------------------------------*/
void Andar::pedidoDescida()
{
    switch (_estado)
    {
        case SEM_PEDIDO:
            _estado = PEDIDO_DESCIDA;
            filaChamadasOrigem.push(_num);
            break;
        case PEDIDO_SUBIDA:
            _estado = PEDIDO_DESTINO;
            break;
        default:
            break;
    }
}

/*---------------------------------------------------------//
* estado_andar WIP
//---------------------------------------------------------*/
void Andar::pedidoDestino()
{

    filaChamadasDestino.push(_num);
    _estado = PEDIDO_DESTINO;

}
