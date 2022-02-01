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
 * METODO: cond_elevador_requisitado
//=================================================================*/

bool Usuario::cond_elevador_requisitado()
{
	return (_andarAtualUsuario >= _andarDestinoUsuario && (vetorAndares[_andarAtualUsuario].estado_andar() == 3 || vetorAndares[_andarAtualUsuario].estado_andar() == 2))||
			(_andarAtualUsuario <= _andarDestinoUsuario && (vetorAndares[_andarAtualUsuario].estado_andar() == 3 || vetorAndares[_andarAtualUsuario].estado_andar() == 1));		
}

/*=================================================================//
 * METODO: cond_subida_requisitada
//=================================================================*/

bool Usuario::cond_subida_requisitada()
{
    return (vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESTINO|| vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_SUBIDA);
}

/*=================================================================//
 * METODO: cond_descida_requisitada
//=================================================================*/

bool Usuario::cond_descida_requisitada()
{
    return (vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESTINO || vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESCIDA);
}

/*=================================================================//
 * METODO: cond_descida
//=================================================================*/

bool Usuario::cond_descida()
{
    return _andarAtualUsuario >= _andarDestinoUsuario && _andarAtualUsuario != 0;
}

/*=================================================================//
 * METODO: cond_subida
//=================================================================*/

bool Usuario::cond_subida()
{
    return _andarAtualUsuario <= _andarDestinoUsuario && _andarAtualUsuario != numAndares-1;
}		
		
/*=================================================================//
 * METODO: cond_destino_requisitado
//=================================================================*/

bool Usuario::cond_destino_requisitado()
{
    return vetorAndares[_andarDestinoUsuario].estado_andar() == 3;
}

/*=================================================================//
 * METODO: setAndarInicial
//=================================================================*/

void Usuario::setAndarInicial()
{   
    std::string temp;
    int num;
    mutexImpressao.lock();
        do{
            std::cout<<CIANO<<"* Digite um andar Inicial, entre 0 e "<< numAndares - 1<<"*"<<BRANCO<<std::endl;
            std::cout<<AZUL<<"*"<<" \t\t ";
            std::cin >> temp;
            num = blindagem(temp);

        }while (num < 0 || num > numAndares - 1);
    mutexImpressao.unlock();
    _andarAtualUsuario = num;
}

/*=================================================================//
 * METODO: botoesOrigem
//=================================================================*/

void Usuario::botoesOrigem()
{
    std::string temp;
    int num;
    mutexImpressao.lock();
        do{ 
            std::cout<<AMARELO<<"//====================================//"<<std::endl;
            std::cout<<"   Voce esta fora do elevador.\n";
            std::cout<<"//====================================//"<< BRANCO<<std::endl;

            std::cout<<CIANO<<"* Digite:"<<std::endl;
            
            if(_andarAtualUsuario != numAndares-1) std::cout<< "* "<<MAGENTA<<"1"<<BRANCO<<" para pressionar o botao de"<<MAGENTA<<" Subida"<<BRANCO << std::endl;
            if(_andarAtualUsuario != 0) std::cout<<"* "<<VERMELHO<< "2"<<BRANCO<<" para pressionar o botao de"<<VERMELHO<<" Descida" <<BRANCO<<std::endl;
            if(_andarAtualUsuario != numAndares-1 && _andarAtualUsuario != 0) std::cout<< "* "<<VERDE <<"3"<< BRANCO<<" para pressionar" <<VERDE <<" Ambos"<< BRANCO<<std::endl;


            std::cin >> temp;
            num = blindagem(temp);
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
 * METODO: botaoSubida
//=================================================================*/

void Usuario::botaoSubida()
{
    vetorAndares[_andarAtualUsuario].pedidoSubida();
}

/*=================================================================//
 * METODO: botaoDescida
//=================================================================*/

void Usuario::botaoDescida()
{
    vetorAndares[_andarAtualUsuario].pedidoDescida();
}

/*=================================================================//
 * METODO: botaoDestino
//=================================================================*/

void Usuario::botaoDestino(int andarDestino)
{
    vetorAndares[andarDestino].pedidoDestino();
}

/*=================================================================//
 * METODO: setAndarDestino
//=================================================================*/

void Usuario::setAndarDestino()
{  
    std::string temp; 
    int num;
    mutexImpressao.lock();
        do{
            std::cout<< "Digite um andar destino, entre 0 e "<< numAndares - 1<<std::endl;
            std::cin >> temp;
            num = blindagem(temp);
        }while (num < 0 || num > numAndares - 1);
    mutexImpressao.unlock();
    _andarDestinoUsuario = num;
}

/*=================================================================//
 * METODO: entrarElevador
//=================================================================*/

void Usuario::entrarElevador()
{   
    _dentroElevador = true;
    numPessoasDentro++;
}

/*=================================================================//
 * METODO: sairElevador
//=================================================================*/

void Usuario::sairElevador()
{   
    _andarAtualUsuario = _andarDestinoUsuario;
    mutexImpressao.lock();
        if (_andarAtualUsuario == 0) std::cout<<"Voce chegou no "<<AMARELO<<"Terreo"<<BRANCO<<std::endl;
        else std::cout<<"Voce chegou no "<<AMARELO<<_andarAtualUsuario<<"º andar"<<BRANCO<<std::endl;
    mutexImpressao.unlock();    
    _dentroElevador = false;
    numPessoasDentro--;
}

/*=================================================================//
 * METODO: novaViagem
//=================================================================*/

bool Usuario::novaViagem()
{   
    std::string temp;
    int valorRetorno;
    mutexImpressao.lock();
    do{
        std::cout<< "Voce deseja fazer uma nova viagem?\n" <<
                    VERDE<<"1 - caso sim.\n"<<
                    VERMELHO<<"0 - caso nao.\n"<< BRANCO<<std::endl;
        std::cin >> temp;
        valorRetorno = blindagem(temp);
    }while(valorRetorno != 0 && valorRetorno != 1);
    mutexImpressao.unlock();    
    return (bool) valorRetorno;
}

/*=================================================================//
 * METODO: threadBehavior
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
