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
    
    UsuarioIA Zeh("Zeh", 4, &porta, &sensor_presenca);
    UsuarioIA Paulo("Paulo", 4, &porta, &sensor_presenca);
    UsuarioIA Joao("Joao", 4, &porta, &sensor_presenca);
    UsuarioIA Carlos("Carlos", 4, &porta, &sensor_presenca);
    

    clp.join();

    Zeh.join();
    Paulo.join();
    Joao.join();
    Carlos.join();

    return 0;
}

//=================================================================//