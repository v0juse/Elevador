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
#include <atomic>


#include "Andar.hpp"
#include "Porta.hpp"
#include "SensorEstadoPorta.hpp"
#include "SensorAndar.hpp"
#include "SensorPresenca.hpp"

/*=================================================================//
 * Definicao da classe                                           
//=================================================================*/

class Controlador: public std::thread
//-----------------------------------------------------------------//
{
    public:
        /*---------------------------------------------------------//
        * construtor: requer a entrada de um ponteiro para um objeto
        * da classe Porta, um objeto da classe SensorEstadoPorta, e
        * para um objeto SensorAndar.
        * 
        * define "andarObjetivo" como -1
        * define "andarAtual" como 0
        * define "tratandoOrigem" como false
        * define "ptrPorta" como o parametro "p"
        * define "ptrSensorEstadoPorta" como o parametro "sp"
        * define "ptrSensorAndar" como o parametro "sa"
        //---------------------------------------------------------*/
        Controlador(Porta* p, SensorEstadoPorta* sp, SensorAndar* sa, bool no_thread = false);

        /*---------------------------------------------------------//
        * destrutor padrao
        //---------------------------------------------------------*/
        ~Controlador();

        /*---------------------------------------------------------//
        * cond_abertura_porta: retorna a condicao para abertura da 
        * porta do elevador quando um pedido e realizado
        //---------------------------------------------------------*/
        bool cond_abertura_porta();

        /*---------------------------------------------------------//
        * def_direcao: realiza um calculo para determinar se o
        * elevador deve subir, descer, ou ficar parado
        * pode retornar -1, 0 ou 1
        //---------------------------------------------------------*/
        void def_direcao();

        /*---------------------------------------------------------//
        * atendeu_andar: 
        * define o valor de "andarObjetivo" em -1 caso "andarAtual" == "andarObjetivo"
        * define o valor de "andarObjetivo" em  0 caso "andarAtual" != "andarObjetivo"
        //---------------------------------------------------------*/
        void atendeu_andar();

        /*---------------------------------------------------------//
		 * threadBehavior: metodo que dita o comportamento da 
         * thread interna
		//---------------------------------------------------------*/
		void threadBehavior();

        /*---------------------------------------------------------//
		 * moverElevador: metodo que altera a posicao do elevador.
         * soma "andarAtual" por "direcao"
		//---------------------------------------------------------*/
        void moverElevador();

        /*---------------------------------------------------------//
		 desligar: finaliza a thread do controlador
		//---------------------------------------------------------*/
        void desligar();

        /*---------------------------------------------------------//
		 get: retorna "andarObjetivo"
		//---------------------------------------------------------*/
        int get_andarObjetivo(){return andarObjetivo;};

        /*---------------------------------------------------------//
		 get: retorna "andarAtual"
		//---------------------------------------------------------*/
        int get_andarAtual(){return andarAtual;};

        /*---------------------------------------------------------//
		 get: retorna "tratandoOrigem"
		//---------------------------------------------------------*/
        bool get_tratandoOrigem(){return tratandoOrigem;};

        /*---------------------------------------------------------//
		 get: retorna "movimento"
		//---------------------------------------------------------*/
        bool get_movimento(){return movimento;};
        


        /*---------------------------------------------------------//
		 get: retorna "movimento"
		//---------------------------------------------------------*/
        void set_andarObjetivo(int obj){andarObjetivo = obj;}

        /*---------------------------------------------------------//
		 get: retorna "movimento"
		//---------------------------------------------------------*/
        void set_andarAtual(int a){andarAtual = a; }




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
		 * mutex utilizado para controlar acesso aos atributos 
         * internos da classe
		//---------------------------------------------------------*/
        
        std::mutex _internAtributes; 
        std::unique_lock<std::mutex> _internAtributesLock;

        std::atomic<bool> end_thread;

        /*---------------------------------------------------------//
		 * funcao a ser passada para a thread na inicializacao
		//---------------------------------------------------------*/

		static void * InternalThreadEntryFunc(void * This)
		{(static_cast<Controlador *>(This))->threadBehavior(); return nullptr;};

//-----------------------------------------------------------------//
};


#endif