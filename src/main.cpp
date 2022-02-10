/*=================================================================//
 * Includes necessarios        
//=================================================================*/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <condition_variable> // std::condition_variable
#include <random>

#include "Controlador.hpp"
#include "UsuarioIA.hpp"
#include "SensorPresenca.hpp"


/*=================================================================//
 * MAIN
//=================================================================*/

int main()
{
    
    Porta porta;
    SensorEstadoPorta sensor_porta;
    SensorAndar sensor_andar;
    SensorPresencaUsuario sensor_presenca;

    Controlador clp(&porta,&sensor_porta,&sensor_andar);
    
    UsuarioIA zee("zee", &porta, &sensor_presenca);
    

    clp.join();
    zee.join();
    return 0;
}

//=================================================================//