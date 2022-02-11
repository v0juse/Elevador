#include "UsuarioIA.hpp"

std::list<UsuarioIA*> UsuarioIA::_listaUsuarios;

/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/

UsuarioIA::UsuarioIA(std::string nome, int nv, Porta* porta, SensorPresencaUsuario *sp):
		std::thread(InternalThreadEntryFunc,this), _internAtributesLock(_internAtributes)
{   
        _numViagens = nv;
        _nome = nome;
        _ptrPorta = porta;
        _dentroElevador = false;
        _ptrSensor = sp;
        _listaUsuarios.push_back(this);
        
        //finaliza setup
        _internAtributesLock.unlock();

}

/*=================================================================//
 * DESTRUTOR       
//=================================================================*/

UsuarioIA::~UsuarioIA()
{

}


/*=================================================================//
 * METODO: cond_elevador_requisitado
//=================================================================*/

bool UsuarioIA::cond_elevador_requisitado()
{
	return (_andarAtualUsuario >= _andarDestinoUsuario && (vetorAndares[_andarAtualUsuario].estado_andar() == 3 || vetorAndares[_andarAtualUsuario].estado_andar() == 2))||
			(_andarAtualUsuario <= _andarDestinoUsuario && (vetorAndares[_andarAtualUsuario].estado_andar() == 3 || vetorAndares[_andarAtualUsuario].estado_andar() == 1));		
}


/*=================================================================//
 * METODO: cond_subida_requisitada
//=================================================================*/

bool UsuarioIA::cond_subida_requisitada()
{
    return (vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESTINO|| vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_SUBIDA);
}

/*=================================================================//
 * METODO: cond_descida_requisitada
//=================================================================*/

bool UsuarioIA::cond_descida_requisitada()
{
    return (vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESTINO || vetorAndares[_andarAtualUsuario].estado_andar() == PEDIDO_DESCIDA);
}

/*=================================================================//
 * METODO: cond_descida
//=================================================================*/

bool UsuarioIA::cond_descida()
{
    return _andarAtualUsuario >= _andarDestinoUsuario && _andarAtualUsuario != 0;
}

/*=================================================================//
 * METODO: cond_subida
//=================================================================*/

bool UsuarioIA::cond_subida()
{
    return _andarAtualUsuario <= _andarDestinoUsuario && _andarAtualUsuario != numAndares-1;
}		
		
/*=================================================================//
 * METODO: cond_destino_requisitado
//=================================================================*/

bool UsuarioIA::cond_destino_requisitado()
{
    return vetorAndares[_andarDestinoUsuario].estado_andar() == 3;
}

/*=================================================================//
 * METODO: setAndarInicial
//=================================================================*/

void UsuarioIA::setAndarInicial()
{   
    std::random_device generator;
	std::mt19937 mt(generator());
	std::uniform_int_distribution<int> distribution(0,numAndares - 1 );// 0..2

    _andarAtualUsuario = distribution(generator);
}

void UsuarioIA::setAndarDestino()
{
    std::random_device generator;
	std::mt19937 mt(generator());
	std::uniform_int_distribution<int> distribution(0,numAndares - 1 );// 0..2

    _andarDestinoUsuario = distribution(generator);
}





/*=================================================================//
 * METODO: botoesOrigem
//=================================================================*/

void UsuarioIA::botoesOrigem()
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

void UsuarioIA::botaoSubida()
{
    vetorAndares[_andarAtualUsuario].pedidoSubida();
}

/*=================================================================//
 * METODO: botaoDescida
//=================================================================*/

void UsuarioIA::botaoDescida()
{
    vetorAndares[_andarAtualUsuario].pedidoDescida();
}

/*=================================================================//
 * METODO: botaoDestino
//=================================================================*/

void UsuarioIA::botaoDestino(int andarDestino)
{
    vetorAndares[andarDestino].pedidoDestino();
}

/*=================================================================//
 * METODO: entrarElevador
//=================================================================*/

void UsuarioIA::entrarElevador()
{   
    _dentroElevador = true;
    vetorEntrou.push_back(_andarAtualUsuario);
    _ptrSensor->registrarEntrada();
    //numPessoasDentro++;
}

/*=================================================================//
 * METODO: sairElevador
//=================================================================*/

void UsuarioIA::sairElevador()
{   
    vetorSaiu.push_back(_andarDestinoUsuario);
    _andarAtualUsuario = _andarDestinoUsuario;
    

    mutexImpressao.lock();
        std::cout<<CIANO<<"//------------------------------------//"<< BRANCO<<std::endl;
        if (_andarAtualUsuario == 0) std::cout<<VERDE<<"*\t "<<_nome<<" chegou no Terreo"<<BRANCO<<std::endl;
        else std::cout<<VERDE<<"*\t "<<_nome<<" chegou no "<<_andarAtualUsuario<<"º andar"<<BRANCO<<std::endl;
        std::cout<<CIANO<<"//------------------------------------//"<< BRANCO<<std::endl;
    mutexImpressao.unlock();    

    _dentroElevador = false;
    _ptrSensor->registrarSaida();
    //numPessoasDentro--;
}

/*=================================================================//
 * METODO: novaViagem
//=================================================================*/

bool UsuarioIA::novaViagem()
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
 * METODO: botaoEmergencia
//=================================================================*/

void UsuarioIA::botaoEmergencia()
{   
    std::random_device generator;
	std::mt19937 mt(generator());
	std::uniform_int_distribution<int> distribution(1,1000);

    int chance = distribution(generator);
    if (chance == 1)
    {  
        mutexEmergencia.lock();
            botaoEmergenciaPressionado = true;
            for(auto& user : _listaUsuarios) user->resetDestino();
        mutexEmergencia.unlock();
    
    }
 
}

void UsuarioIA::resetDestino()
{
    
   _andarDestinoUsuario = 0;

}


/*=================================================================//
 * METODO: threadBehavior
//=================================================================*/

void UsuarioIA::threadBehavior()
{   
    //acesso aos atributos internos da classe
    _internAtributes.lock();

    setAndarInicial();
    mutexImpressao.lock();
        std::cout<<CIANO<<"//------------------------------------//"<< BRANCO<<std::endl;
        std::cout<<CIANO<<"* "<<_nome<<" esta no andar: " << _andarAtualUsuario << BRANCO<<std::endl;
        std::cout<<CIANO<<"//------------------------------------//"<< BRANCO<<std::endl;
    mutexImpressao.unlock();
    
    //TESTANDO
    volatile int i = 0;

    while(i++ < _numViagens)
    {

        setAndarDestino();
        mutexImpressao.lock();
            std::cout<<CIANO<<"//------------------------------------//"<< BRANCO<<std::endl;
            std::cout<<CIANO<<"* "<<_nome<<" deseja chegar no andar: " << _andarDestinoUsuario << BRANCO<<std::endl;
            std::cout<<CIANO<<"//------------------------------------//"<< BRANCO<<std::endl;
        mutexImpressao.unlock();
        
        //fora do elevador
        while(!_ptrPorta->abertaNoAndar(_andarAtualUsuario))
        {
            if(!cond_elevador_requisitado() && cond_descida()) botaoDescida();
            if(!cond_elevador_requisitado() && cond_subida()) botaoSubida();
        }

        //espera a porta do andar abrir
        //_ptrPorta->esperaPorta(_andarAtualUsuario);
        
        //conferir depois que usuarios desceram
        if(_ptrSensor->numPessoasDentro() >= maxNumPessoas)continue;   

        //dentro do elevador
        entrarElevador();
        mutexImpressao.lock();
            std::cout<<CIANO<<"//------------------------------------//"<< BRANCO<<std::endl;
            std::cout<<CIANO<<"*      "<<_nome<<" entrou no Elevador"<< BRANCO<<std::endl;
            std::cout<<CIANO<<"//------------------------------------//"<< BRANCO<<std::endl;
        mutexImpressao.unlock();


        
        //sem expulsao por lotacao (modelo)
        while(!_ptrPorta->abertaNoAndar(_andarDestinoUsuario))
        {   
            if(!cond_destino_requisitado()) vetorAndares[_andarDestinoUsuario].pedidoDestino();
            botaoEmergencia();
            // mutexEmergencia.lock();
            // if(botaoEmergenciaPressionado)_andarDestinoUsuario = 0;
            // mutexEmergencia.unlock();
        } 
            
        //_ptrPorta->esperaPorta(_andarDestinoUsuario);
        sairElevador();
        
    }
    mutexImpressao.lock();
        std::cout<<AMARELO<<"//------------------------------------//"<< BRANCO<<std::endl;
        std::cout<<AMARELO<<"\t Lista do "<<_nome<< BRANCO<<std::endl;
        std::cout<<AMARELO<<" Entrou:\t\t Saiu:"<< BRANCO<<std::endl;

    while(!vetorEntrou.empty())
    {   
            std::cout<<AMARELO<<"\t"<<vetorEntrou.front()<< BRANCO;
            vetorEntrou.erase(vetorEntrou.begin());
            std::cout<<AMARELO<<"\t\t"<<vetorSaiu.front()<< BRANCO << std::endl;
            vetorSaiu.erase(vetorSaiu.begin());
    }

        std::cout<<AMARELO<<"//------------------------------------//"<< BRANCO<<std::endl;
    mutexImpressao.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

//=================================================================//
