#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

/*=================================================================//
 * Includes
//=================================================================*/
#include <iostream>
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <condition_variable> // std::condition_variable
#include <random>


#include "Andar.hpp"
#include "Porta.hpp"
#include "SensorEstadoPorta.hpp"
#include "SensorAndar.hpp"

/*=================================================================//
 * Definicao da classe                                           
//=================================================================*/

class Controlador: public std::thread
//-----------------------------------------------------------------//
{
    public:
        /*---------------------------------------------------------//
        * construtor WIP
        //---------------------------------------------------------*/
        Controlador(Porta* p);

        /*---------------------------------------------------------//
        * destrutor WIP
        //---------------------------------------------------------*/
        ~Controlador();

        /*---------------------------------------------------------//
        * cond_abertura_porta WIP
        //---------------------------------------------------------*/
        bool cond_abertura_porta();

        /*---------------------------------------------------------//
        * def_direcao   WIP
        //---------------------------------------------------------*/
        void def_direcao();

        /*---------------------------------------------------------//
        * def_direcao   WIP
        //---------------------------------------------------------*/
        int remove(bool);

        /*---------------------------------------------------------//
        * def_direcao   WIP
        //---------------------------------------------------------*/
        void trata_origem();

        /*---------------------------------------------------------//
        * alternar_movimento   WIP
        //---------------------------------------------------------*/
        void alternar_movimento();

        /*---------------------------------------------------------//
        * alcancou_andar   WIP
        //---------------------------------------------------------*/
        bool alcancou_andar();

        /*---------------------------------------------------------//
        * alcancou_andar   WIP
        //---------------------------------------------------------*/
        void atendeu_andar();

        /*---------------------------------------------------------//
		 * metodos que dita o comportamento da thread interna
		//---------------------------------------------------------*/
		void threadBehavior();

        /*---------------------------------------------------------//
		 * metodos que dita o comportamento da thread interna
		//---------------------------------------------------------*/
        void moverElevador();
//-----------------------------------------------------------------//
    private:
        /*---------------------------------------------------------//
        * ATRIBUTOS 
        //---------------------------------------------------------*/
        int andarObjetivo;
        int andarAtual;
        bool tratandoOrigem;
        bool movimento;
        Porta* ptrPorta;
        SensorEstadoPorta* ptrSensorEstadoPorta;
        SensorAndar* ptrSensorAndar;

        /*---------------------------------------------------------//
		 * funcao a ser passada para a thread na inicializacao
		//---------------------------------------------------------*/

		static void * InternalThreadEntryFunc(void * This)
		{((Controlador *)This)->threadBehavior(); return nullptr;};

//-----------------------------------------------------------------//
};


#endif