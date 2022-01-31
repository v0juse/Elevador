#include "Andar.hpp"

int Andar::_num_andares = 0;
std::mutex mutexAndares;

Andar vetorAndares[numAndares];

Andar::Andar()
{   
    mutexAndares.lock();
        _num = _num_andares++;
        _estado = SEM_PEDIDO;
    mutexAndares.unlock();
}
Andar::~Andar()
{
    _num_andares--;
}

enum ESTADOS_ANDAR Andar::estado_andar()
{   
    std::unique_lock<std::mutex> lock(mutexAndares);
    return _estado;
}


void Andar::atendeuAndar()
{   
    std::unique_lock<std::mutex> lock(mutexAndares);
    _estado = SEM_PEDIDO;
}

/*---------------------------------------------------------//
* estado_andar WIP
//---------------------------------------------------------*/
void Andar::pedidoSubida()
{   
    std::unique_lock<std::mutex> lock(mutexAndares);
    switch (_estado)
    {
        case SEM_PEDIDO:
            _estado = PEDIDO_SUBIDA;
            mutexFilasChamadas.lock(); //rc fila de chamadas
                filaChamadasOrigem.push(_num);
            mutexFilasChamadas.unlock();
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
    std::unique_lock<std::mutex> lock(mutexAndares);
    switch (_estado)
    {
        case SEM_PEDIDO:
            _estado = PEDIDO_DESCIDA;
            mutexFilasChamadas.lock();//rc fila de chamadas 
                filaChamadasOrigem.push(_num);
            mutexFilasChamadas.unlock();
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
    std::unique_lock<std::mutex> lock(mutexAndares);

    mutexFilasChamadas.lock();//rc fila de chamadas 
        filaChamadasDestino.push(_num);
    mutexFilasChamadas.unlock();
    
    _estado = PEDIDO_DESTINO;

}
