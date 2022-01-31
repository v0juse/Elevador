#include "Controlador.hpp"

/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/
Controlador::Controlador(Porta* p): std::thread(InternalThreadEntryFunc,this) 
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

void Controlador::moverElevador()
{
    movimento = true;
    andarAtual += direcao;
    movimento = false;
}

void Controlador::threadBehavior()
{   
    
    std::unique_lock<std::mutex> lock(mutexFilasChamadas, std::defer_lock);
    while(_sistemON)
    {   
        //inicio rc da lista de chamadas------------------------------------
	    lock.lock();//entra rc
        
        if(filaChamadasDestino.empty() && filaChamadasOrigem.empty() ) novaChamada.wait(lock);

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

        lock.unlock();
        //fim rc da lista de chamadas----------------------------------------
        //volta para elevador livre
        if(vetorAndares[andarObjetivo].estado_andar() == SEM_PEDIDO) continue;

        def_direcao();

        while(andarObjetivo != -1)
        {
            if(cond_abertura_porta()) 
            {
                ptrPorta->abrir();
                vetorAndares[andarAtual].atendeuAndar();
                if(andarAtual == andarObjetivo) andarObjetivo = -1;//objetivo concluido

                mutexImpressao.lock();
                std::cout << "porta aberta/n";
                mutexImpressao.unlock();    
                //TODO entrada/expulsao de usuario
                while(ptrSensorEstadoPorta->objetoBloqueante()); //busy wait ate a porta nao estar bloqueada

                ptrPorta->fechar();
            }

            if(andarObjetivo = -1) break;//objetivo ja concluido

            moverElevador();




        }  

    }



}
