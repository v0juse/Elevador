#include "Controlador.hpp"

/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/
Controlador::Controlador(Porta* p, SensorEstadoPorta* sp, SensorAndar* sa): 
std::thread(InternalThreadEntryFunc,this),
_internAtributesLock(_internAtributes), end_thread(false)
{
    andarObjetivo = -1;
    andarAtual = 0;
    tratandoOrigem = false;
    ptrPorta = p;
    ptrSensorEstadoPorta = sp;
    ptrSensorAndar = sa;
     

    mutexImpressao.lock();
        std::cout<<AMARELO<<"//====================================//"<< BRANCO<<std::endl;
        std::cout<<AMARELO<<"\t Elevador no andar: " << andarAtual << BRANCO<<std::endl;
        std::cout<<AMARELO<<"//====================================//"<< BRANCO<<std::endl;
    mutexImpressao.unlock();

    //finaliza setup
    _internAtributesLock.unlock();
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
    while(!ptrSensorAndar->andarAlcancado());
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
    
    while(!end_thread)
    {   
        //inicio rc da lista de chamadas------------------------------------

	    lockFila.lock();//entra rc
        if(filaChamadasDestino.empty() && filaChamadasOrigem.empty() )
        { 
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

                atendeu_andar();

                mutexImpressao.lock();
                    std::cout<<MAGENTA<<"//====================================//"<< BRANCO<<std::endl;
                    std::cout<<MAGENTA<<"       Porta "<<VERDE<<"ABERTA." << BRANCO<<std::endl;
                    std::cout<<MAGENTA<<"//====================================//"<< BRANCO<<std::endl;
                mutexImpressao.unlock();

                while(ptrSensorEstadoPorta->objetoBloqueante()); //busy wait ate a porta nao estar bloqueada
                
                //std::this_thread::sleep_for(std::chrono::milliseconds(1));
                ptrPorta->fechar(andarAtual);
            }

            if(andarObjetivo == -1) break;//objetivo ja concluido
            
            
            mutexEmergencia.lock();
            if(botaoEmergenciaPressionado)
            {   
                botaoEmergenciaPressionado = false;
                while (!filaChamadasDestino.empty()) filaChamadasDestino.pop();
                while (!filaChamadasOrigem.empty()) filaChamadasOrigem.pop();   
                andarObjetivo = -1;
                andarAtual = 0; 
                direcao = 0;
                
                mutexImpressao.lock();
                    std::cout<<VERMELHO<<"//------------------------------------//"<< BRANCO<<std::endl;
                    std::cout<<VERMELHO<<"*\t  EMERGENCIA!!! "<<BRANCO<<std::endl;
                    std::cout<<VERMELHO<<"//------------------------------------//"<< BRANCO<<std::endl;
                mutexImpressao.unlock(); 
                mutexEmergencia.unlock();           
                
                ptrPorta->abrir(0);
                //std::this_thread::sleep_for(std::chrono::seconds(3));
                ptrPorta->fechar(0); 
                atendeu_andar();
                //break;

            
            }
            else mutexEmergencia.unlock();
            
            
            
            moverElevador();
            mutexImpressao.lock();
                std::cout<<AMARELO<<"//====================================//"<< BRANCO<<std::endl;
                std::cout<<AMARELO<<"\t Elevador no andar: " << andarAtual << BRANCO<<std::endl;
                std::cout<<AMARELO<<"//====================================//"<< BRANCO<<std::endl;
            mutexImpressao.unlock();



        }  

    }



}


void Controlador::desligar()
{
    end_thread = true;
    novaChamada.notify_all();
}