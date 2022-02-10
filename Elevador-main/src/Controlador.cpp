#include "Controlador.hpp"

/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/
Controlador::Controlador(Porta* p, SensorEstadoPorta* sp, SensorAndar* sa, SensorPresenca *spresenca): std::thread(InternalThreadEntryFunc,this) 
{
    andarObjetivo = -1;
    andarAtual = 0;
    tratandoOrigem = false;
    ptrPorta = p;
    ptrSensorEstadoPorta = sp;
    ptrSensorAndar = sa;
    ptrSensorP = spresenca;

    mutexImpressao.lock();
        std::cout<<AMARELO<<"//====================================//"<< BRANCO<<std::endl;
        std::cout<<AMARELO<<"\t Elevador no andar: " << andarAtual << BRANCO<<std::endl;
        std::cout<<AMARELO<<"//====================================//"<< BRANCO<<std::endl;
    mutexImpressao.unlock();
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
 * METODO: atendeu_andar
//=================================================================*/
void Controlador::atendeu_andar()
{
    andarObjetivo = (andarAtual == andarObjetivo) ? -1 : andarObjetivo;
    vetorAndares[andarAtual].atendeuAndar();
}

/*=================================================================//
 * METODO: moverElevador 
//=================================================================*/

void Controlador::moverElevador()
{
    movimento = true;
    andarAtual += direcao;
    movimento = false;
}

/*=================================================================//
 * METODO: threadBehavior    
 * metodos que dita o comportamento da thread interna  
//=================================================================*/
void Controlador::threadBehavior()
{   
    
    //acesso aos atributos internos da classe
    _internAtributes.lock();
    std::unique_lock<std::mutex> lockFila(mutexFilasChamadas, std::defer_lock);
    while(1)
    {   
        //inicio rc da lista de chamadas------------------------------------

	    lockFila.lock();//entra rc
        if(filaChamadasDestino.empty() && filaChamadasOrigem.empty() )
        { 
            mutexImpressao.lock();
                std::cout<<AMARELO<<"* "<<VERDE<<"  Elevador livre"<<BRANCO<<", aguardando...     "<<AMARELO<<"*"<<BRANCO<<std::endl;
            mutexImpressao.unlock();

            novaChamada.wait(lockFila);
        }



        if(!filaChamadasDestino.empty())
        {
            andarObjetivo = filaChamadasDestino.front();
            filaChamadasDestino.pop();
        }
        else 
        {
            andarObjetivo = filaChamadasOrigem.front();
            filaChamadasOrigem.pop();
        }

        lockFila.unlock();
        //fim rc da lista de chamadas----------------------------------------
        //volta para elevador livre
        if(vetorAndares[andarObjetivo].estado_andar() == SEM_PEDIDO) continue;

        def_direcao();

        while(andarObjetivo != -1)
        {
            if(cond_abertura_porta()) 
            {
                ptrPorta->abrir(andarAtual);
                vetorAndares[andarAtual].atendeuAndar();
                if(andarAtual == andarObjetivo) andarObjetivo = -1;//objetivo concluido

                mutexImpressao.lock();
                    std::cout << MAGENTA<<"Porta aberta\n"<<BRANCO;
                mutexImpressao.unlock();    
                //TODO entrada/expulsao de usuario

                //while(ptrSensorEstadoPorta->objetoBloqueante()); //busy wait ate a porta nao estar bloqueada
                //while(ptrSensorP->numPessoasDentro() >= maxNumPessoas){}
                ptrPorta->fechar(andarAtual);
            }

            if(andarObjetivo == -1) break;//objetivo ja concluido

            moverElevador();
            mutexImpressao.lock();
                std::cout<<AMARELO<<"//====================================//"<< BRANCO<<std::endl;
                std::cout<<AMARELO<<"\t Elevador no andar: " << andarAtual << BRANCO<<std::endl;
                std::cout<<AMARELO<<"//====================================//"<< BRANCO<<std::endl;
            mutexImpressao.unlock();



        }  

    }



}
