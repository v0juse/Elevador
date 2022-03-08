/*=================================================================//
 * Includes
//=================================================================*/

#include "SensorPresenca.hpp"


/*=================================================================//
 * CONSTRUTOR
//=================================================================*/
SensorPresencaUsuario::SensorPresencaUsuario()
{
    _numPessoasDentro = 0;
}

/*=================================================================//
 * DESTRUTOR
//=================================================================*/
SensorPresencaUsuario::~SensorPresencaUsuario()
{
    
}

/*=================================================================//
 * METODO:registrarEntrada
//=================================================================*/
void SensorPresencaUsuario::registrarEntrada()
{
    std::unique_lock<std::mutex> lock(_mutexPresenca);
    _numPessoasDentro++;

}

/*=================================================================//
 * METODO:registrarSaida
//=================================================================*/
void SensorPresencaUsuario::registrarSaida()
{
    std::unique_lock<std::mutex> lock(_mutexPresenca);
     _numPessoasDentro--;

}

/*=================================================================//
 * METODO:numPessoasDentro
//=================================================================*/
int SensorPresencaUsuario::numPessoasDentro()
{
    std::unique_lock<std::mutex> lock(_mutexPresenca);
    return _numPessoasDentro;

}
