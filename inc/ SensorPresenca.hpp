#ifndef SENSOR_PRESENCA
#define SENSOR_PRESENCA
/*=================================================================//
 * Includes
//=================================================================*/
#include <mutex>

class SensorPresencaUsuario
{
    public:
        SensorPresencaUsuario();
        ~SensorPresencaUsuario();

        void registrarEntrada();

        void registrarSaida();

        int numPessoasDentro();


    private:
        int _numPessoasDentro;
        
        std::mutex _mutexPresenca;



};











#endif