#include "Andar.hpp"

int Andar::_num_andares = 0;
std::mutex Andar::mutexAndares;

Andar vetorAndares[numAndares];
//std::vector<std::unique_ptr<Andar*>> vetorAndares;


/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/
Andar::Andar()
{   
    mutexAndares.lock();
        _num = _num_andares++;
        _estado = SEM_PEDIDO;
    mutexAndares.unlock();
}

/*=================================================================//
 * DESTRUTOR                                       
//=================================================================*/
Andar::~Andar()
{
    _num_andares--;
}

/*=================================================================//
 * METODO: ESTADO_ANDAR                                 
//=================================================================*/
enum ESTADOS_ANDAR Andar::estado_andar()
{   
    std::unique_lock<std::mutex> lock(mutexAndares);
    return _estado;
}

/*=================================================================//
 * METODO: ATENDEU_ANDAR                                      
//=================================================================*/
void Andar::atendeuAndar()
{   
    std::unique_lock<std::mutex> lock(mutexAndares);
    _estado = SEM_PEDIDO;
}

/*=================================================================//
 * METODO: PEDIDO_SUBIDA                                    
//=================================================================*/
void Andar::pedidoSubida()
{   
    std::unique_lock<std::mutex> lock(mutexAndares);
    switch (_estado)
    {
        case SEM_PEDIDO:
            _estado = PEDIDO_SUBIDA;
            mutexFilasChamadas.lock(); //rc fila de chamadas
                filaChamadasOrigem.push(_num);
                novaChamada.notify_one();
            mutexFilasChamadas.unlock();
            
            break;
        case PEDIDO_DESCIDA:
            _estado = PEDIDO_DESTINO;
            break;
        default:
            break;
    }
}

/*=================================================================//
 * METODO: PEDIDO_DESCIDA                                 
//=================================================================*/
void Andar::pedidoDescida()
{
    std::unique_lock<std::mutex> lock(mutexAndares);
    switch (_estado)
    {
        case SEM_PEDIDO:
            _estado = PEDIDO_DESCIDA;
            mutexFilasChamadas.lock();//rc fila de chamadas 
                filaChamadasOrigem.push(_num);
                novaChamada.notify_one();
            mutexFilasChamadas.unlock();
            
            break;
        case PEDIDO_SUBIDA:
            _estado = PEDIDO_DESTINO;
            break;
        default:
            break;
    }
}

/*=================================================================//
 * METODO: PEDIDO_DESTINO                                  
//=================================================================*/
void Andar::pedidoDestino()
{
    std::unique_lock<std::mutex> lock(mutexAndares);

    mutexFilasChamadas.lock();//rc fila de chamadas 
    
        filaChamadasDestino.push(_num);
        novaChamada.notify_one();
    
    mutexFilasChamadas.unlock();

    
    
    _estado = PEDIDO_DESTINO;

}



/*=================================================================//
 * METODO: PEDIDO_DESTINO                                  
//=================================================================*/
 int Andar::num()
 {
     return _num;
 }

/*=================================================================//
 * METODO: SET_ANDAR                             
//=================================================================*/
void Andar::setEstadoAndar(enum ESTADOS_ANDAR novo_estado)
{
    _estado = novo_estado;
}