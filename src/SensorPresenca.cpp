#include "SensorPresenca.hpp"


SensorPresencaUsuario::SensorPresencaUsuario()
{
    _numPessoasDentro = 0;
}

SensorPresencaUsuario::~SensorPresencaUsuario()
{
    
}

void SensorPresencaUsuario::registrarEntrada()
{
    std::unique_lock<std::mutex> lock(_mutexPresenca);
    _numPessoasDentro++;

}

void SensorPresencaUsuario::registrarSaida()
{
    std::unique_lock<std::mutex> lock(_mutexPresenca);
     _numPessoasDentro--;

}

int SensorPresencaUsuario::numPessoasDentro()
{
    std::unique_lock<std::mutex> lock(_mutexPresenca);
    return _numPessoasDentro;

}
