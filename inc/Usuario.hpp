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
        
        Usuario(std::string nome, int numViagens);
        
        /*---------------------------------------------------------//
         * destrutor padrao
        //---------------------------------------------------------*/
        
        ~Usuario();

        /*---------------------------------------------------------//
         * metodo que faz o objeto "pensar" por 0~2 segundos,
         * escolhido aleatoriamente.timed mensure c++
        //---------------------------------------------------------*/
        
        duration<double> Filosofar();

        /*---------------------------------------------------------//
         * tenta coletar entre 2~n garrafas, onde n é o
         * numero maximo de garrafas que este filosofo consegue 
         * pegar, e calcula o tempo usado para isso.
        //---------------------------------------------------------*/
        
        duration<double> Pegar_garrafas(uint);
        
        /*---------------------------------------------------------//
         * faz o objeto gastar 1 segundo para consumir as bebidas.
        //---------------------------------------------------------*/
        
        duration<double> Beber();

        /*---------------------------------------------------------//
         * metodo usado para sinalizar a garrafa que ela pode se
         * posicionar como disponivel novamente.
        //---------------------------------------------------------*/
        
        void Retornar_garrafas();
        
        /*---------------------------------------------------------//
         * metodo get para o atributo "_id"
        //---------------------------------------------------------*/
        
        int id();

        /*---------------------------------------------------------//
		 * adiciona uma garrafa acessivel para o filosofo
		//---------------------------------------------------------*/

		void Adicionar_garrafa(Garrafa*);

        /*---------------------------------------------------------//
		 * metodos que dita o comportamento da thread
		//---------------------------------------------------------*/

		void threadBehavior();

		/*---------------------------------------------------------//
		 * metodos get para os tempos que o filosofo passou em cada
		 * estado
		//---------------------------------------------------------*/

		std::chrono::duration<double> t_tranquilo();
		std::chrono::duration<double> t_com_sede();
		std::chrono::duration<double> t_bebendo();

		/*---------------------------------------------------------//
		 *metodo get que retorna o atributo "_simulationON"
		//---------------------------------------------------------*/

		bool simulationON();

        /*---------------------------------------------------------//
		 *informa se a simulacao pode ser iniciada, ou terminada.
		//---------------------------------------------------------*/

		static void iniciaSimulacao(void);
		static void terminaSimulacao(void);

		/*---------------------------------------------------------//
		 * metodo para obter uma impressao formatada dos dados que cada
		 * filosofo passou em cada estado (tranquilo, com sede e bebendo),
		 * e tempo medio de espera
		//---------------------------------------------------------*/

		void printResults();
        
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
        
		int andarAtualUsuario; 
		int andarDestinoUsuario;
		
		bool cond_elevador_requisitado();
		bool cond_descida();
		bool cond_subida();
		bool cond_destino_requisitado();

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

        /*---------------------------------------------------------//
		 * variavel utilizada para verificar se a simulacao deve 
         * estar acontecendo, ou nao.
		//---------------------------------------------------------*/

        static bool _simulationON;


		/*---------------------------------------------------------//
		 * funcao a ser passada para a thread na inicializacao
		//---------------------------------------------------------*/

		static void * InternalThreadEntryFunc(void * This)
		{((Usuario *)This)->threadBehavior(); return nullptr;};

//-----------------------------------------------------------------//
};

#endif /* USUARIO_HPP_ */
