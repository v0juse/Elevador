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
    * define "_num" a partir de "_num_andares"
    * define _estado como "SEM_PEDIDO"
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
    * pedidoSubida: 
      caso "_estado" for "SEM_PEDIDO" -> "_estado" recebe "PEDIDO_SUBIDA"
      caso "_estado" for "PEDIDO_DESCIDA" -> "_estado" recebe "PEDIDO_DESTINO"
    //---------------------------------------------------------*/
    void pedidoSubida();

    /*---------------------------------------------------------//
    * pedidoDescida:
      caso "_estado" for "SEM_PEDIDO" -> "_estado" recebe "PEDIDO_DESCIDA"
      caso "_estado" for "PEDIDO_SUBIDA" -> "_estado" recebe "PEDIDO_DESTINO"
    //---------------------------------------------------------*/
    void pedidoDescida();

    /*---------------------------------------------------------//
    * pedidoDestino: "_estado" recebe "PEDIDO_DESTINO"
    //---------------------------------------------------------*/
    void pedidoDestino();

    /*---------------------------------------------------------//
    * num: retorna o numero do andar
    //---------------------------------------------------------*/
    int num();

    /*---------------------------------------------------------//
    * num: retorna o numero do andar
    //---------------------------------------------------------*/
    void setEstadoAndar(enum ESTADOS_ANDAR novo_estado);


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