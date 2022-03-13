#include "Porta.hpp"

/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/
Porta::Porta()
{
    //aberta = false;
    
    for(int i = 0; i < numAndares; i++)
    {
        std::condition_variable* tmp;
        tmp = new std::condition_variable;
        portasCondsPtrs.emplace_back(tmp);
        _abertaNoAndar[i] = false;
    }
}

/*=================================================================//
 * DESTRUTOR       
//=================================================================*/
Porta::~Porta()
{

}

/*=================================================================//
 * METODO: abertaNoAndar     
//=================================================================*/
bool Porta::abertaNoAndar(int num)
{
    return _abertaNoAndar[num];
}

/*=================================================================//
 * METODO: cond_abertura_porta
 * realiza um broadcast para os usuarios que estao esperando a 
 * abertura da porta
//=================================================================*/
void Porta::abrir(int num)
{   
    std::unique_lock<std::mutex> lock(mutexPorta);
    //aberta = true;
    _abertaNoAndar[num] = true;
    lock.unlock();

    portasCondsPtrs[num]->notify_all(); //porta aberta em cada andar

    portaQualquerAberta.notify_all(); //porta aberta em um andar qualquer 
}

/*=================================================================//
 * METODO: def_direcao
//=================================================================*/
void Porta::fechar(int num)
{
    std::unique_lock<std::mutex> lock(mutexPorta);
    _abertaNoAndar[num] = false;
    //aberta = false;
}

/*=================================================================//
 * METODO: esperaPorta
//=================================================================*/
void Porta::esperaPorta(int num)
{
    std::unique_lock<std::mutex> lock(mutexPorta, std::defer_lock);
	lock.lock(); //entra rc

    (portasCondsPtrs[num])->wait(lock);
}

