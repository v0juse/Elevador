#ifndef ANDAR_HPP_
#define ANDAR_HPP_

/*=================================================================//
 * Includes / Enums
//=================================================================*/

#include "Utility.h"

enum ESTADOS_ANDAR{SEM_PEDIDO, PEDIDO_SUBIDA, PEDIDO_DESCIDA, PEDIDO_DESTINO};

/*=================================================================//
 * Definicao da Classe
//=================================================================*/

class Andar
//-----------------------------------------------------------------//
{
public:
    /*---------------------------------------------------------//
    * construtor padrao
    //---------------------------------------------------------*/
    Andar();

    /*---------------------------------------------------------//
    * destrutor padrao
    //---------------------------------------------------------*/
    ~Andar();

    /*---------------------------------------------------------//
    * estado_andar: retorna o estado do andar selecionado
    //---------------------------------------------------------*/
    enum ESTADOS_ANDAR estado_andar();

    /*---------------------------------------------------------//
    * atendeuAndar: restaura o estado do andar selecionado para
    * SEM_PEDIDO com uso de mutex
    //---------------------------------------------------------*/
    void atendeuAndar();

    /*---------------------------------------------------------//
    * pedidoSubida: metodo que registra os pedidos de subida
    //---------------------------------------------------------*/
    void pedidoSubida();

    /*---------------------------------------------------------//
    * pedidoDescida: metodo que registra os pedidos de descida
    //---------------------------------------------------------*/
    void pedidoDescida();

    /*---------------------------------------------------------//
    * pedidoDescida: metodo que registra os pedidos de destino
    //---------------------------------------------------------*/
    void pedidoDestino();

//-------------------------------------------------------------// 
private:
    /*---------------------------------------------------------//
    * ATRIBUTOS 
    //---------------------------------------------------------*/
    int _num;
    enum ESTADOS_ANDAR _estado;
    
    static int _num_andares;
    static std::mutex mutexAndares;
//-------------------------------------------------------------//
};

extern Andar vetorAndares[numAndares];

#endif