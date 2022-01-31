#ifndef UTILITY_H_
#define UTILITY_H_


#include <queue>
//==================================== Constantes ========================================//
const int numAndares = 6;
//Capacidade da fila de chamadas
const int capacidade = 20*(numAndares - 1);
const int maxNumPessoas =  4;
//=======================================================================================//

extern std::queue<int> filaChamadasOrigem, filaChamadasDestino;

extern int objetoBloqueante;
extern int direcao;
extern int numPessoasDentro;



#endif