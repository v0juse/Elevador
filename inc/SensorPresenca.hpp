#ifndef SENSOR_PRESENCA_USUARIO
#define SENSOR_PRESENCA_USUARIO

/*=================================================================//
 * Includes
//=================================================================*/

#include <mutex>

/*=================================================================//
 * Classe
//=================================================================*/
class SensorPresencaUsuario
{
//-----------------------------------------------------------------//
public:
    /*---------------------------------------------------------//
    * Construtor padrao
    //---------------------------------------------------------*/
    SensorPresencaUsuario();

    /*---------------------------------------------------------//
    * Destrutor padrao
    //---------------------------------------------------------*/
    ~SensorPresencaUsuario();

    /*---------------------------------------------------------//
    * Metodo que registra a entrada de um usuario no elevador
    //---------------------------------------------------------*/
    void registrarEntrada();

    /*---------------------------------------------------------//
    * Metodo que registra a saida de um usuario do elevador
    //---------------------------------------------------------*/
    void registrarSaida();

    /*---------------------------------------------------------//
    * Metodo que retorna o numero de pessoas dentro do elevador
    //---------------------------------------------------------*/
    int numPessoasDentro();

//-----------------------------------------------------------------//
private:
    /*---------------------------------------------------------//
    * Atributos
    //---------------------------------------------------------*/
    int _numPessoasDentro;
    
    std::mutex _mutexPresenca;

//-----------------------------------------------------------------//
};











#endif