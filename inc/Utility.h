#include <queue>
//==================================== Constantes ========================================//
const int numAndares = 6;
//Capacidade da fila de chamadas
const int capacidade = 20*(numAndares - 1);
const int maxNumPessoas =  4;
//=======================================================================================//




std::queue<int> filaChamadasOrigem, filaChamadasDestino;

int andarAtual = 0;
int estadoAndar[numAndares];
bool portaAberta = false;
bool movimento = 0;
int objetoBloqueante = 0;
int direcao = 0;
int numPessoasDentro = 0;
