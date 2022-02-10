#include "SensorEstadoPorta.hpp"

/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/
SensorEstadoPorta::SensorEstadoPorta()
{
    
}

/*=================================================================//
 * DESTRUTOR       
//=================================================================*/
SensorEstadoPorta::~SensorEstadoPorta()
{

}

/*=================================================================//
 * METODO: cond_abertura_porta
//=================================================================*/
bool SensorEstadoPorta::objetoBloqueante()
{
    int valor;

    std::random_device generator;
    std::mt19937 mt(generator());
    std::uniform_int_distribution<int> distribution(1,100);// 1..n

    valor = distribution(generator);

    if (valor <= 10) return true;
    return false;
}



