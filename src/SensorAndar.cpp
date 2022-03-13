#include "SensorAndar.hpp"

/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/
SensorAndar::SensorAndar()
{
    
}

/*=================================================================//
 * DESTRUTOR       
//=================================================================*/
SensorAndar::~SensorAndar()
{

}

/*=================================================================//
 * METODO: cond_abertura_porta
//=================================================================*/
bool SensorAndar::andarAlcancado()
{
    int valor;

    std::random_device generator;
    std::mt19937 mt(generator());
    std::uniform_int_distribution<int> distribution(1,100);// 1..n

    valor = distribution(generator);

    if (valor <= PROP_ANDAR_ALCANCADO) return true;
    return false;
}



