#ifndef SENSOR_PRESENCA_USUARIO
#define SENSOR_PRESENCA_USUARIO

#include <mutex>

class SensorPresencaUsuario
{
public:
    SensorPresencaUsuario();
    ~SensorPresencaUsuario(){}

    void registrarEntrada();

    void registrarSaida();

    int numPessoasDentro();


private:
    int _numPessoasDentro;
    
    std::mutex _mutexPresenca;



};











#endif