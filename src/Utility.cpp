#include "Utility.h"


std::queue<int> filaChamadasOrigem, filaChamadasDestino;

int objetoBloqueante = 0;
int direcao = 0;
int numPessoasDentro = 0;
bool _sistemON;
bool botaoEmergenciaPressionado = false;

std::mutex mutexFilasChamadas;
std::mutex mutexImpressao;
std::mutex mutexEmergencia;
std::condition_variable novaChamada; 

/*=================================================================//
 * BLINDAGEM       
//=================================================================*/

int blindagem(std::string s)
{
    try { return stoi(s); }

    catch (...) { return -1; }
    
    return -1;
}

 