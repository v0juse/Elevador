#include "Usuario.hpp"


/*=================================================================//
 * Atributos static
//=================================================================*/


/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/

Usuario::Usuario(std::string nome):
		std::thread(InternalThreadEntryFunc,this)
{
        _nome = nome;
}

/*=================================================================//
 * DESTRUTOR       
//=================================================================*/

Usuario::~Usuario()
{

}

/*=================================================================//
 * METODO: Filosofar
//=================================================================*/

bool Usuario::cond_elevador_requisitado()
{
	return (_andarAtualUsuario >= _andarDestinoUsuario && (vetorAndares[_andarAtualUsuario].estado_andar() == 3 || vetorAndares[_andarAtualUsuario].estado_andar() == 2))||
			(_andarAtualUsuario <= _andarDestinoUsuario && (vetorAndares[_andarAtualUsuario].estado_andar() == 3 || vetorAndares[_andarAtualUsuario].estado_andar() == 1));		
}

bool Usuario::cond_subida_requisitada()
{
    return (vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESTINO|| vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_SUBIDA);
}

bool Usuario::cond_descida_requisitada()
{
    return (vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESTINO || vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESCIDA);
}

bool Usuario::cond_descida()
{
    return _andarAtualUsuario >= _andarDestinoUsuario && _andarAtualUsuario != 0;
}

bool Usuario::cond_subida()
{
    return _andarAtualUsuario <= _andarDestinoUsuario && _andarAtualUsuario != numAndares-1;
}		
		

bool Usuario::cond_destino_requisitado()
{
    return vetorAndares[_andarDestinoUsuario].estado_andar() == 3;
}

/*---------------------------------------------------------//
    * TODO
//---------------------------------------------------------*/
void Usuario::setAndarInicial()
{   
    int num;
    mutexImpressao.lock();
        do{
            std::cout<< "Digite um andar inicial, entre 0 e "<< numAndares - 1<<std::endl;
            std::cin >> num;
        }while (num < 0 || num > numAndares - 1);
    mutexImpressao.unlock();
    _andarAtualUsuario = num;
}

/*---------------------------------------------------------//
* TODO
//---------------------------------------------------------*/
void Usuario::botoesOrigem()
{
   int num;
    mutexImpressao.lock();
        do{
            std::cout<< "Voce esta fora do elevadors,/n Digite 1 para pressionar o botao de subida, /n 2 para pressionar o botao de descida /n ou 3 para pressionar ambos"<<std::endl;
            std::cin >> num;
        }while (num < 1 || num > 3);
    mutexImpressao.unlock();

    switch (num)
    {
    case 1:
        if(!cond_subida_requisitada()) vetorAndares[_andarAtualUsuario].pedidoSubida();
        break;
    case 2:
        if(!cond_descida_requisitada()) vetorAndares[_andarAtualUsuario].pedidoDescida();
        break;
    case 3: 
        if(!cond_subida_requisitada()) vetorAndares[_andarAtualUsuario].pedidoSubida();
        if(!cond_descida_requisitada()) vetorAndares[_andarAtualUsuario].pedidoDescida();
        break;
    default:
        break;
    }
}


/*---------------------------------------------------------//
    * TODO
//---------------------------------------------------------*/



void Usuario::botaoSubida()
{
    vetorAndares[_andarAtualUsuario].pedidoSubida();
}

/*---------------------------------------------------------//
    * TODO
//---------------------------------------------------------*/
void Usuario::botaoDescida()
{
    vetorAndares[_andarAtualUsuario].pedidoDescida();
}

/*---------------------------------------------------------//
    * TODO
//---------------------------------------------------------*/
void Usuario::botaoDestino(int andarDestino)
{
    vetorAndares[andarDestino].pedidoDestino();
}

void Usuario::setAndarDestino()
{   
    int num;
    mutexImpressao.lock();
        do{
            std::cout<< "Digite um andar destino, entre 0 e "<< numAndares - 1<<std::endl;
            std::cin >> num;
        }while (num < 0 || num > numAndares - 1);
    mutexImpressao.unlock();
    _andarDestinoUsuario = num;
}

/*---------------------------------------------------------//
    * TODO
//---------------------------------------------------------*/
void Usuario::entrarElevador()
{
    numPessoasDentro++;
}

/*---------------------------------------------------------//
    * TODO
//---------------------------------------------------------*/
void Usuario::sairElevador()
{
    numPessoasDentro--;
}

/*---------------------------------------------------------//
    * metodos que dita o comportamento da thread interna
//---------------------------------------------------------*/
void Usuario::threadBehavior()
{
    setAndarInicial();

    //fora do elevador
    botoesOrigem();
    



}

//=================================================================//
