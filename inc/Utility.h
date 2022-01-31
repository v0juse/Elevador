#ifndef UTILITY_H_
#define UTILITY_H_


#include <queue>
//==================================== Constantes ========================================//
const int numAndares = 6;
//Capacidade da fila de chamadas
const int capacidade = 20*(numAndares - 1);
const int maxNumPessoas =  4;
//=======================================================================================//

std::queue<int> filaChamadasOrigem, filaChamadasDestino;

int objetoBloqueante = 0;
int direcao = 0;
int numPessoasDentro = 0;



#endif