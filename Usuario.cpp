#include "Usuario.hpp"


/*=================================================================//
 * Atributos static
//=================================================================*/

std::vector<std::unique_ptr<std::condition_variable>> Filosofo::filosofos_conds_ptrs;
unsigned int Filosofo::_num_filosofos = 0;
std::mutex Filosofo::mutex_garafas;
bool Filosofo::_simulationON = false;
std::mutex Filosofo::mutex_escrita;

/*=================================================================//
 * CONSTRUTOR                                         
//=================================================================*/

Filosofo::Filosofo(int id, int num_rodadas):
		std::thread(InternalThreadEntryFunc,this),
		_t_tranquilo(0),_t_com_sede(0),_t_bebendo(0)
{
    _id = id;

    _num_filosofos++;
    std::condition_variable* tmp;

    tmp = new std::condition_variable;

    filosofos_conds_ptrs.emplace_back(tmp);

    _num_bebedeiras = num_rodadas;
}

/*=================================================================//
 * DESTRUTOR       
//=================================================================*/

Filosofo::~Filosofo()
{
	_num_filosofos--;
	//std::cout << _num_filosofos << std::endl;

	if(_num_filosofos == 0) filosofos_conds_ptrs.clear();
}

/*=================================================================//
 * METODO: Filosofar
//=================================================================*/

bool Usuario::cond_elevador_requisitado()
{
	return (andarAtualUsuario >= andarDestinoUsuario && (Andar.estado_andar(andarAtualUsuario) == 3 || Andar.estado_andar(andarAtualUsuario) == 2))||
			(andarAtualUsuario <= andarDestinoUsuario && (Andar.estado_andar(andarAtualUsuario) == 3 || Andar.estado_andar(andarAtualUsuario) == 1));		
}



bool Usuario::cond_descida()
{
    return andarAtualUsuario >= andarDestinoUsuario && andarAtualUsuario != 0;
}

bool Usuario::cond_subida()
{
    return andarAtualUsuario <= andarDestinoUsuario && andarAtualUsuario != numAndares-1;
}		
		

bool Usuario::cond_destino_requisitado()
{
    return estado_andar[andarDestinoUsuario] == 3;
}

//=================================================================//
