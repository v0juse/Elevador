#ifndef UTILITY_H_
#define UTILITY_H_


#include <queue>
#include <mutex>
#include <condition_variable>

/*=====================================================================//
 * Defines      
//=====================================================================*/

#define DEBUG 0
#define VERMELHO "\033[1;31;1m"
#define VERDE "\033[1;32;1m"
#define AMARELO "\033[1;33;1m"
#define AZUL "\033[1;34;1m"
#define MAGENTA "\033[1;35;1m"
#define CIANO "\033[1;36;1m"
#define BRANCO "\033[0;m"



//==================================== Constantes ========================================//
const int numAndares = 6;
//Capacidade da fila de chamadas
const int capacidade = 20*(numAndares - 1);
const int maxNumPessoas =  4;
//=======================================================================================//

extern std::queue<int> filaChamadasOrigem, filaChamadasDestino;
extern std::mutex mutexFilasChamadas;
extern std::mutex mutexImpressao;

extern int objetoBloqueante;
extern int direcao;
extern int numPessoasDentro;
extern bool _sistemON;
extern std::condition_variable novaChamada; 



#endif