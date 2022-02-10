#ifndef PORTA_HPP_
#define PORTA_HPP_

/*=================================================================//
 * Includes
//=================================================================*/

#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <condition_variable> // std::condition_variable
#include <vector>

#include "Utility.h"

//TODO: remodelar a porta como uma por andar
/*=================================================================//
 * Definicao da Classe
//=================================================================*/

class Porta
//-----------------------------------------------------------------//
{
public:
    /*---------------------------------------------------------//
    * construtor padrao
    //---------------------------------------------------------*/
    Porta();

    /*---------------------------------------------------------//
    * destrutor padrao
    //---------------------------------------------------------*/
    ~Porta();

    /*---------------------------------------------------------//
    * abrir: metodo para abrir a porta
    //---------------------------------------------------------*/
    void abrir(int num);

    /*---------------------------------------------------------//
    * fechar: metodo para fechar a porta
    //---------------------------------------------------------*/
    void fechar(int num);

    /*---------------------------------------------------------//
    * esperaPorta: metodo espera a abertura da porta feito na 
    * classe Andar   
    //---------------------------------------------------------*/
    void esperaPorta(int num);


    /*---------------------------------------------------------//
    * abertaNoAndar: metodo que retorna true caso a porta esteja 
    * aberta no andar 'num', false caso contrario 
    * classe Andar   
    //---------------------------------------------------------*/
    bool abertaNoAndar(int num);
private:
    
    /*---------------------------------------------------------//
    * ATRIBUTOS 
    //---------------------------------------------------------*/
    bool aberta;
    
    bool _abertaNoAndar[numAndares];

    std::mutex mutexPorta;
    std::vector<std::unique_ptr<std::condition_variable>> portasCondsPtrs;
    std::condition_variable portaQualquerAberta;
//-----------------------------------------------------------------//
};


#endif