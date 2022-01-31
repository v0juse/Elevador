#ifndef FILOSOFO_H_
#define FILOSOFO_H_

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

#define NUM_TENTATIVAS_MAX 1

#include "Utility.h"

using namespace std::chrono;

/*=================================================================//
 * Definicao das classes                                           
//=================================================================*/

class Filosofo: public std::thread{
//-----------------------------------------------------------------//
    
    public:
        /*---------------------------------------------------------//
         * construtor com valor de inicializacao do atributo "_id"
        //---------------------------------------------------------*/
        
        Filosofo(int id, int num_rodadas);
        
        /*---------------------------------------------------------//
         * destrutor padrao
        //---------------------------------------------------------*/
        
        ~Filosofo();

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
         * atributo para identificacao do filosofo
        //---------------------------------------------------------*/
        
        int _id;
        
        /*---------------------------------------------------------//
         * lista de garrafas para definir quais garrafas este
         * objeto e capaz de pegar
        //---------------------------------------------------------*/
        
        std::list<Garrafa*> lista_garrafa;

        /*---------------------------------------------------------//
		 * lista de garrafas para definir quais estao em sua posse
         * em qualquer momento.
		//---------------------------------------------------------*/

        std::list<Garrafa*> lista_garrafa_na_mao;
        
        /*---------------------------------------------------------//
		 * mutexes e conds.
		//---------------------------------------------------------*/

        static std::mutex mutex_garafas;
        static std::mutex mutex_escrita;
        static std::vector<std::unique_ptr<std::condition_variable>> filosofos_conds_ptrs;

        /*---------------------------------------------------------//
		 * variavel utilizada para armazenar a quantidade de 
         * filosofos a partir do arquivo de entrada.
		//---------------------------------------------------------*/

        static unsigned int _num_filosofos;

        /*---------------------------------------------------------//
		 * variavel utilizada para verificar se a simulacao deve 
         * estar acontecendo, ou nao.
		//---------------------------------------------------------*/

        static bool _simulationON;

        /*---------------------------------------------------------//
		 * metodo para retiras as garrafas quando sao suficientes
		 * supoe que ja esta dentro da rc
		//---------------------------------------------------------*/

		void retirarGarrafas(uint);

		/*---------------------------------------------------------//
		 * metodo para realizar a reserva de todas as garrafas,
		 * com o objetivo de evitar uma espera prolongada,
		 * supoe que ja esta na rc
		//---------------------------------------------------------*/

		void reservarGarrafas();

		/*---------------------------------------------------------//
		 * metodo para retirar todas as reservas efetuadas por este
		 * filosofo, supoe que ja esta na rc
		//---------------------------------------------------------*/

		void desbloquearGarrafas();

		/*---------------------------------------------------------//
		 * atributos relativos ao tempo que o filosofo passou em cada
		 * estado
		//---------------------------------------------------------*/
        
		std::chrono::duration<double> _t_tranquilo;
		std::chrono::duration<double> _t_com_sede;
		std::chrono::duration<double> _t_bebendo;

		/*---------------------------------------------------------//
		 * o numero de vezes que esse filosofo deve beber
		//---------------------------------------------------------*/

		int _num_bebedeiras;

		/*---------------------------------------------------------//
		 * funcao a ser passada para a thread na inicializacao
		//---------------------------------------------------------*/

		static void * InternalThreadEntryFunc(void * This)
		{((Filosofo *)This)->threadBehavior(); return nullptr;};

//-----------------------------------------------------------------//
};

#endif /* FILOSOFO_H_ */
