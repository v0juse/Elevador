#ifndef USUARIO_HPP_
#define USUARIO_HPP_


/*=================================================================//
 * Includes necessarios        
//=================================================================*/


#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <utility>
#include <chrono>
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <condition_variable> // std::condition_variable
#include <random>


#include "Andar.hpp"
#include "Porta.hpp"
//#include "Utility.h"

using namespace std::chrono;

/*=================================================================//
 * Definicao das classes                                           
//=================================================================*/

class Usuario: public std::thread
{
//-----------------------------------------------------------------//
    
    public:
        /*---------------------------------------------------------//
         * construtor com valor de inicializacao do atributo "_id"
        //---------------------------------------------------------*/
        
        Usuario(std::string nome);
        
        /*---------------------------------------------------------//
         * destrutor padrao
        //---------------------------------------------------------*/
        
        ~Usuario();

        /*---------------------------------------------------------//
         * TODO
        //---------------------------------------------------------*/
        virtual void setAndarInicial();

        /*---------------------------------------------------------//
         * TODO
        //---------------------------------------------------------*/

        virtual void setAndarDestino();

        /*---------------------------------------------------------//
         * TODO
        //---------------------------------------------------------*/

        void botaoSubida();
        
        /*---------------------------------------------------------//
         * TODO
        //---------------------------------------------------------*/
        void botaoDescida();

        /*---------------------------------------------------------//
         * TODO
        //---------------------------------------------------------*/
        void botaoDestino(int andarDestino);

        /*---------------------------------------------------------//
         * TODO
        //---------------------------------------------------------*/
        void entrarElevador();

        /*---------------------------------------------------------//
         * TODO
        //---------------------------------------------------------*/
        void sairElevador();

        /*---------------------------------------------------------//
		 * metodos que dita o comportamento da thread interna
		//---------------------------------------------------------*/
		void threadBehavior();
        
//-----------------------------------------------------------------//
    
    private:
        
        /*---------------------------------------------------------//
         * atributo para identificacao do usuario
        //---------------------------------------------------------*/
        
        std::string _nome;

		/*---------------------------------------------------------//
         * atributo que define o numero de viagens restantes para um 
		 usuario
        //---------------------------------------------------------*/
		int _numViagens;
        
		 /*---------------------------------------------------------//
         * atributo para localizacao de andares do usuario
        //---------------------------------------------------------*/
        
		int _andarAtualUsuario; 
		int _andarDestinoUsuario;
		
		bool cond_elevador_requisitado();
		bool cond_descida();
		bool cond_subida();
		bool cond_destino_requisitado();
        bool cond_subida_requisitada();
        bool cond_descida_requisitada();

        /*---------------------------------------------------------//
		 * mutexes e conds.
		//---------------------------------------------------------*/
		/*
        static std::mutex mutex_garafas;
        static std::mutex mutex_escrita;
        static std::vector<std::unique_ptr<std::condition_variable>> filosofos_conds_ptrs;

        /*---------------------------------------------------------//
		 * variavel utilizada para armazenar a quantidade de 
         * usuarios a partir do arquivo de entrada.
		//---------------------------------------------------------*/
	
        static unsigned int _num_usuarios;

        void botoesOrigem();

		/*---------------------------------------------------------//
		 * funcao a ser passada para a thread na inicializacao
		//---------------------------------------------------------*/

		static void * InternalThreadEntryFunc(void * This)
		{((Usuario *)This)->threadBehavior(); return nullptr;};

//-----------------------------------------------------------------//
};

#endif /* USUARIO_HPP_ */
