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
#include "Usuario.hpp"


/*=================================================================//
 * MAIN
//=================================================================*/

int main()
{
    Porta porta;
    SensorEstadoPorta sensor_porta;
    SensorAndar sensor_andar;

    Controlador clp(&porta,&sensor_porta,&sensor_andar);
    
    Usuario zee("zee", &porta);
    
    

    clp.join();
    zee.join();
    return 0;
}

//=================================================================//