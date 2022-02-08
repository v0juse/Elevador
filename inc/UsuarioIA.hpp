#ifndef USUARIOIA_HPP_
#define USUARIOIA_HPP_


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

#include "Porta.hpp"
#include "Usuario.hpp"
//#include "Utility.h"

using namespace std::chrono;

/*=================================================================//
 * Definicao das classes                                           
//=================================================================*/

class UsuarioIA: public std::thread
{
//-----------------------------------------------------------------//
    
    public:
        /*---------------------------------------------------------//
         * construtor com valor de inicializacao do atributo "_id"
        //---------------------------------------------------------*/
        
        UsuarioIA(std::string nome, Porta* porta);
        
        /*---------------------------------------------------------//
         * destrutor padrao
        //---------------------------------------------------------*/
        
        ~UsuarioIA();

        /*---------------------------------------------------------//
         * metodo que recebe o andar inicial selecionado pelo
         * usuario
        //---------------------------------------------------------*/
        virtual void setAndarInicial();

        /*---------------------------------------------------------//
         * metodo que recebe o andar de destino selecionado pelo
         * usuario
        //---------------------------------------------------------*/

        virtual void setAndarDestino();

        /*---------------------------------------------------------//
         * metodo que adiciona o andar em que foi pressionado o botao
         * de subida
        //---------------------------------------------------------*/

        void botaoSubida();
        
        /*---------------------------------------------------------//
         * metodo que adiciona o andar em que foi pressionado o botao
         * de descida
        //---------------------------------------------------------*/
        void botaoDescida();

        /*---------------------------------------------------------//
         * metodo que adiciona o pedido de destino a fila de destinos
        //---------------------------------------------------------*/
        void botaoDestino(int andarDestino);

        /*---------------------------------------------------------//
         * metodo que incrementa o numero de pessoas no elevador
        //---------------------------------------------------------*/
        void entrarElevador();

        /*---------------------------------------------------------//
         * metodo que retira o usuario do elevador quando este chega 
         * ao seu destino
        //---------------------------------------------------------*/
        void sairElevador();

        /*---------------------------------------------------------//
         * metodo que verifica se o usuario chegou ao destino 
         * desejado
        //---------------------------------------------------------*/
        bool viagemSatisfeita();

        
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
		 * variavel utilizada para armazenar a quantidade de 
         * usuarios a partir do arquivo de entrada.
		//---------------------------------------------------------*/
	
        static unsigned int _num_usuarios;

        void botoesOrigem();

        Porta *_ptrPorta;

        bool _dentroElevador;
		
        
        bool novaViagem();
        
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
		{((Usuario *)This)->threadBehavior(); return nullptr;};

//-----------------------------------------------------------------//
};

#endif /* USUARIO_HPP_ */
