#include "Usuario.hpp"


/*=================================================================//
 * Atributos static
//=================================================================*/


/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/

Usuario::Usuario(std::string nome, Porta* porta):
		std::thread(InternalThreadEntryFunc,this)
{   
        _nome = nome;
        _ptrPorta = porta;
        _dentroElevador = false;
}

/*=================================================================//
 * DESTRUTOR       
//=================================================================*/

Usuario::~Usuario()
{

}

/*=================================================================//
 * METODO: WIP
//=================================================================*/

bool Usuario::cond_elevador_requisitado()
{
	return (_andarAtualUsuario >= _andarDestinoUsuario && (vetorAndares[_andarAtualUsuario].estado_andar() == 3 || vetorAndares[_andarAtualUsuario].estado_andar() == 2))||
			(_andarAtualUsuario <= _andarDestinoUsuario && (vetorAndares[_andarAtualUsuario].estado_andar() == 3 || vetorAndares[_andarAtualUsuario].estado_andar() == 1));		
}

/*=================================================================//
 * METODO: WIP
//=================================================================*/

bool Usuario::cond_subida_requisitada()
{
    return (vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESTINO|| vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_SUBIDA);
}

/*=================================================================//
 * METODO: WIP
//=================================================================*/

bool Usuario::cond_descida_requisitada()
{
    return (vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESTINO || vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESCIDA);
}

/*=================================================================//
 * METODO: WIP
//=================================================================*/

bool Usuario::cond_descida()
{
    return _andarAtualUsuario >= _andarDestinoUsuario && _andarAtualUsuario != 0;
}

/*=================================================================//
 * METODO: WIP
//=================================================================*/

bool Usuario::cond_subida()
{
    return _andarAtualUsuario <= _andarDestinoUsuario && _andarAtualUsuario != numAndares-1;
}		
		
/*=================================================================//
 * METODO: WIP
//=================================================================*/

bool Usuario::cond_destino_requisitado()
{
    return vetorAndares[_andarDestinoUsuario].estado_andar() == 3;
}

/*=================================================================//
 * METODO: WIP
//=================================================================*/

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

/*=================================================================//
 * METODO: WIP
//=================================================================*/

void Usuario::botoesOrigem()
{
   int num;
    mutexImpressao.lock();
        do{ 
            std::cout<< "Voce esta fora do elevador,\nDigite";
            
            if(_andarAtualUsuario != numAndares-1) std::cout<< " 1 para pressionar o botao de subida" << std::endl;
            if(_andarAtualUsuario != 0) std::cout<< " 2 para pressionar o botao de descida" <<std::endl;
            if(_andarAtualUsuario != numAndares-1 && _andarAtualUsuario != 0) std::cout<< " ou 3 para pressionar ambos"<<std::endl;
            std::cin >> num;
        }while ((num < 1 || num > 3)||
        (_andarAtualUsuario == numAndares-1 && num !=2 ) ||
        (_andarAtualUsuario == 0 && num !=1 ) );
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

/*=================================================================//
 * METODO: WIP
//=================================================================*/

void Usuario::botaoSubida()
{
    vetorAndares[_andarAtualUsuario].pedidoSubida();
}

/*=================================================================//
 * METODO: WIP
//=================================================================*/

void Usuario::botaoDescida()
{
    vetorAndares[_andarAtualUsuario].pedidoDescida();
}

/*=================================================================//
 * METODO: WIP
//=================================================================*/

void Usuario::botaoDestino(int andarDestino)
{
    vetorAndares[andarDestino].pedidoDestino();
}

/*=================================================================//
 * METODO: WIP
//=================================================================*/

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

/*=================================================================//
 * METODO: WIP
//=================================================================*/

void Usuario::entrarElevador()
{   
    _dentroElevador = true;
    numPessoasDentro++;
}

/*=================================================================//
 * METODO: WIP
//=================================================================*/

void Usuario::sairElevador()
{   
    _andarAtualUsuario = _andarDestinoUsuario;
    mutexImpressao.lock();
        std::cout<<"Voce chegou no " <<_andarAtualUsuario<<"º andar"<<std::endl;
    mutexImpressao.unlock();    
    _dentroElevador = false;
    numPessoasDentro--;
}

/*=================================================================//
 * METODO: WIP
//=================================================================*/

bool Usuario::novaViagem()
{   
    bool resposta;
    mutexImpressao.lock();
    do{
        std::cout<< "Voce deseja fazer uma nova viagem?\n" <<
                    "1 - caso sim\n"<<
                    "0 - caso nao\n"<<std::endl;
        std::cin >> resposta;
    }while(resposta != 0 && resposta != 1);
    mutexImpressao.unlock();    
    return resposta;
}

/*=================================================================//
 * METODO: threadBehavior
 * metodos que dita o comportamento da thread interna
//=================================================================*/

void Usuario::threadBehavior()
{   
    setAndarInicial();
    do
    {
        

        //fora do elevador
        botoesOrigem();
        
        //espera a porta do andar abrir
        _ptrPorta->esperaPorta(_andarAtualUsuario);
        
        entrarElevador();
        setAndarDestino();
        vetorAndares[_andarDestinoUsuario].pedidoDestino();

        _ptrPorta->esperaPorta(_andarDestinoUsuario);

        sairElevador();

    }while(novaViagem());
}

//=================================================================//
