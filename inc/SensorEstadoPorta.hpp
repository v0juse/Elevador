#ifndef SENSOR_ESTADO_PORTA_HPP_
#define SENSOR_ESTADO_PORTA_HPP_

/*=================================================================//
 * Includes
//=================================================================*/

#include <random>

/*=================================================================//
 * Definicao da Classe
//=================================================================*/

class SensorEstadoPorta
//-----------------------------------------------------------------//
{
public:
    /*---------------------------------------------------------//
    * construtor 
    //---------------------------------------------------------*/
    SensorEstadoPorta();

    /*---------------------------------------------------------//
    * destrutor
    //---------------------------------------------------------*/
    ~SensorEstadoPorta();

    /*---------------------------------------------------------//
    * estado_andar
    //---------------------------------------------------------*/
    bool objetoBloqueante();

//-----------------------------------------------------------------// 
private:
    /*---------------------------------------------------------//
    * ATRIBUTOS 
    //---------------------------------------------------------*/
    //bool aberta;
//-----------------------------------------------------------------//
};


#endif