#include "SensorPresenca.hpp"


SensorPresencaUsuario::SensorPresencaUsuario()
{
    _numPessoasDentro = 0;
}

void SensorPresencaUsuario::registrarEntrada()
{
    std::unique_lock<std::mutex> lock(mutexPresenca);
    _numPessoasDentro++;

}

void SensorPresencaUsuario::registrarSaida()
{
    std::unique_lock<std::mutex> lock(mutexPresenca);
     _numPessoasDentro--;

}

int SensorPresencaUsuario::numPessoasDentro()
{
    std::unique_lock<std::mutex> lock(mutexPresenca);
    return _numPessoasDentro;

}
