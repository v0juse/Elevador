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
        * construtor: requer a entrada de um ponteiro para um objeto
        * da classe Porta, um objeto da classe SensorEstadoPorta, e
        * para um objeto SensorAndar, inicializando; ptrPorta,
        * ptrSensorEstadoPorta e ptrAndar, respectivamente
        //---------------------------------------------------------*/
        Controlador(Porta* p, SensorEstadoPorta* sp, SensorAndar* sa);

        /*---------------------------------------------------------//
        * destrutor padrao
        //---------------------------------------------------------*/
        ~Controlador();

        /*---------------------------------------------------------//
        * cond_abertura_porta: condicao para abertura da porta do 
        * elevador quando um pedido e realizado
        //---------------------------------------------------------*/
        bool cond_abertura_porta();

        /*---------------------------------------------------------//
        * def_direcao: realiza um calculo para determinar se o
        * elevador deve subir, descer, ou ficar parado
        //---------------------------------------------------------*/
        void def_direcao();

        /*---------------------------------------------------------//
        * def_direcao: metodo de remocao de um item da fila de 
        * pedidos de origem e de destino, de forma alternada
        //---------------------------------------------------------*/
        int remove(bool);

        /*---------------------------------------------------------//
        * trata_origem: funcao para determinar de qual das duas
        * filas deve ser removido o proximo pedido
        //---------------------------------------------------------*/
        void trata_origem();

        /*---------------------------------------------------------//
        * alternar_movimento: manipula a variavel "movimento" de 
        * forma alternada
        //---------------------------------------------------------*/
        void alternar_movimento();

        /*---------------------------------------------------------//
        * atendeu_andar: metodo que atualiza o andar objetivo
        //---------------------------------------------------------*/
        void atendeu_andar();

        /*---------------------------------------------------------//
		 * threadBehavior: metodo que dita o comportamento da 
         * thread interna
		//---------------------------------------------------------*/
		void threadBehavior();

        /*---------------------------------------------------------//
		 * moverElevador: metodo que altera a posicao do elevador    
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
		 * mutex utilizado para controlar acesso aos atributos 
         * internos da classe
		//---------------------------------------------------------*/
        std::mutex _internAtributes; 
        std::unique_lock<std::mutex> _internAtributesLock;


        /*---------------------------------------------------------//
		 * funcao a ser passada para a thread na inicializacao
		//---------------------------------------------------------*/

		static void * InternalThreadEntryFunc(void * This)
		{((Controlador *)This)->threadBehavior(); return nullptr;};

//-----------------------------------------------------------------//
};


#endif