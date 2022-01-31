#include "Controlador.hpp"

/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/
Controlador::Controlador(Porta* p)
{
    andarObjetivo = -1;
    tratandoOrigem = false;
    ptrPorta = p;
}

/*=================================================================//
 * DESTRUTOR       
//=================================================================*/
Controlador::~Controlador()
{

}

/*=================================================================//
 * METODO: cond_abertura_porta
//=================================================================*/
bool Controlador::cond_abertura_porta()
{
    int estAndar = vetorAndares[andarAtual].estado_andar();
    return ((estAndar == 3) || 
            (estAndar == 1 && direcao != -1) || 
            (estAndar == 2 && direcao != 1) || 
            (estAndar != 0 && direcao == 0)) ||
            (andarAtual == andarObjetivo );
}

/*=================================================================//
 * METODO: def_direcao
//=================================================================*/
void Controlador::def_direcao()
{
    if   (andarAtual == andarObjetivo ) direcao = 0;
    else direcao = andarAtual > andarObjetivo ? -1 : 1;
}

/*=================================================================//
 * METODO: remove
//=================================================================*/
int Controlador::remove(bool selectQueue)
{
    int aux;
    if(selectQueue)
    {    
        int tamFilaOrigem = filaChamadasOrigem.size();
        if(tamFilaOrigem== 0) return -1; 

        aux = filaChamadasOrigem.front();
        filaChamadasOrigem.pop();
    }
    else
    {   
        int tamFilaDestino = filaChamadasDestino.size();
        if(tamFilaDestino == 0) return -1; 

        aux = filaChamadasDestino.front();
        filaChamadasOrigem.pop();
    }
    return aux;
}

/*=================================================================//
 * METODO: trata_origem
//=================================================================*/
void Controlador::trata_origem()
{
    tratandoOrigem = (filaChamadasDestino.size() != 0) ? 0:1;
    andarObjetivo = remove(tratandoOrigem);
}

/*=================================================================//
 * METODO: alternar_movimento
//=================================================================*/
void Controlador::alternar_movimento()
{
    movimento = !movimento;
}

/*=================================================================//
 * METODO: alcancou_andar
//=================================================================*/
bool Controlador::alcancou_andar()
{
    if (andarAtual != andarObjetivo)
    {
        andarAtual = andarAtual + direcao;
        alternar_movimento();
        return false;
    }
    return true;
}

/*=================================================================//
 * METODO: atendeu_andar
//=================================================================*/
void Controlador::atendeu_andar()
{
    andarObjetivo = (andarAtual == andarObjetivo) ? -1 : andarObjetivo;
    vetorAndares[andarAtual].atendeuAndar();
}

