#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

/*=================================================================//
 * Includes
//=================================================================*/

#include "Utility.h"
#include "Andar.hpp"

/*=================================================================//
 * Definicao da classe                                           
//=================================================================*/

class Controlador
//-----------------------------------------------------------------//
{
    public:
        /*---------------------------------------------------------//
        * construtor WIP
        //---------------------------------------------------------*/
        Controlador();

        /*---------------------------------------------------------//
        * destrutor WIP
        //---------------------------------------------------------*/
        ~Controlador();

        /*---------------------------------------------------------//
        * cond_abertura_porta WIP
        //---------------------------------------------------------*/
        bool cond_abertura_porta();

        /*---------------------------------------------------------//
        * def_direcao   WIP
        //---------------------------------------------------------*/
        void def_direcao();

        /*---------------------------------------------------------//
        * def_direcao   WIP
        //---------------------------------------------------------*/
        int remove(bool);

        /*---------------------------------------------------------//
        * def_direcao   WIP
        //---------------------------------------------------------*/
        void trata_origem();

        /*---------------------------------------------------------//
        * alternar_movimento   WIP
        //---------------------------------------------------------*/
        void alternar_movimento();

        /*---------------------------------------------------------//
        * alcancou_andar   WIP
        //---------------------------------------------------------*/
        bool alcancou_andar();

        /*---------------------------------------------------------//
        * alcancou_andar   WIP
        //---------------------------------------------------------*/
        bool atendeu_andar(int);

//-----------------------------------------------------------------//
    private:
        /*---------------------------------------------------------//
        * ATRIBUTOS 
        //---------------------------------------------------------*/
        int andarObjetivo;
        bool tratandoOrigem;

//-----------------------------------------------------------------//
};


#endif