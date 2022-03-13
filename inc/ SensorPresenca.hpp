#ifndef SENSOR_PRESENCA
#define SENSOR_PRESENCA
/*=================================================================//
 * Includes
//=================================================================*/
#include <mutex>

/*=================================================================//
 * Definicao da Classe
//=================================================================*/
class SensorPresencaUsuario
//-----------------------------------------------------------------//
{
    public:
        /*---------------------------------------------------------//
        * define "_numPessoasDentro" como 0
        //---------------------------------------------------------*/
        SensorPresencaUsuario();

        /*---------------------------------------------------------//
        * destrutor padrao
        //---------------------------------------------------------*/
        ~SensorPresencaUsuario();

        /*---------------------------------------------------------//
        * aumenta "_numPessoasDentro" em 1
        //---------------------------------------------------------*/
        void registrarEntrada();

        /*---------------------------------------------------------//
        * diminui "_numPessoasDentro" em 1
        //---------------------------------------------------------*/
        void registrarSaida();

        /*---------------------------------------------------------//
        * retorna o valor de "_numPessoasDentro"
        //---------------------------------------------------------*/
        int numPessoasDentro();

//-----------------------------------------------------------------//
    private:
        /*---------------------------------------------------------//
        * ATRIBUTOS 
        //---------------------------------------------------------*/
        int _numPessoasDentro;
        
        std::mutex _mutexPresenca;
//-----------------------------------------------------------------//


};











#endif