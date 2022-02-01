#include "Utility.h"


std::queue<int> filaChamadasOrigem, filaChamadasDestino;

int objetoBloqueante = 0;
int direcao = 0;
int numPessoasDentro = 0;
bool _sistemON;
std::mutex mutexFilasChamadas;
std::mutex mutexImpressao;
std::condition_variable novaChamada; 
 