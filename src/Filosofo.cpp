#include "Filosofo.h"


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

duration<double> Filosofo::Filosofar()
{
	steady_clock::time_point inicio,fim;
	duration<double> tempo;
	int segs;


	std::random_device generator;
	std::mt19937 mt(generator());
	std::uniform_int_distribution<int> distribution(0,2);// 0..2

	segs = distribution(generator);

	inicio = steady_clock::now();

	std::this_thread::sleep_for (std::chrono::seconds(segs));

	fim = steady_clock::now();
	tempo = duration_cast<duration<double>>(fim - inicio);
	_t_tranquilo += tempo;

	return tempo;
}

/*=================================================================//
 * METODO: Pegar_garrafas
//=================================================================*/

duration<double> Filosofo::Pegar_garrafas(uint n_garrafas_desejadas )
{
	//contar tempo
	steady_clock::time_point inicio,fim;
	inicio = steady_clock::now();
	duration<double> tempo;

	unsigned int n_garrafas_disponiveis, n_esperas = 0;

	//unlock automatico quando destruido
	std::unique_lock<std::mutex> lock(mutex_garafas, std::defer_lock);
	lock.lock();//entra rc

	while(1)
	{
		n_garrafas_disponiveis = 0;

		for(std::list<Garrafa*>::iterator it =lista_garrafa.begin();
				it != lista_garrafa.end(); it++)
		{
			if((*it)->disponivel() && !((*it)->isBloqueada(id())))
			{

				n_garrafas_disponiveis++;
				if(DEBUG)
				{
					mutex_escrita.lock();
					std::cout<<"\033[1;34;1mFilosofo: "<<id()<<" viu garrafa "
							<<(*it)->id()
							<<" como disponivel, somando "<<n_garrafas_disponiveis
							<<" garrafas disponiveis \n reserva: "<<
							(*it)->reserva()<<"\033[0;m"<<std::endl;

					mutex_escrita.unlock();
				}

				if(n_garrafas_disponiveis == n_garrafas_desejadas)
				{
					//so sai assim
					retirarGarrafas(n_garrafas_desejadas);//aqui faz a parte de setar indisponivel

					//conta tempo
					fim = steady_clock::now();
					tempo = duration_cast<duration<double>>(fim - inicio);
					_t_com_sede += tempo;

					lock.unlock(); //sai rc
					return tempo;
				}
			}
		}
		
		n_esperas++;
		if(n_esperas > NUM_TENTATIVAS_MAX)
		{
			reservarGarrafas();
			n_esperas = 0;
		}

		(filosofos_conds_ptrs[id()])->wait(lock);
	}
	return tempo;
}

/*=================================================================//
 * METODO: Beber
//=================================================================*/

duration<double> Filosofo::Beber()
{
	duration<double> tempo;
	steady_clock::time_point inicio,fim;
	inicio = steady_clock::now();



	std::this_thread::sleep_for (std::chrono::seconds(1));


	fim = steady_clock::now();

	tempo = duration_cast<duration<double>>(fim - inicio);
	_t_bebendo += tempo;

	return tempo;
}

/*=================================================================//
 * METODO: Retornar_garrafa
//=================================================================*/

void Filosofo::Retornar_garrafas()
{
	Garrafa* tmp;
	std::pair<int,int> filosofos_da_garrafa;

	std::unique_lock<std::mutex> lock(mutex_garafas, std::defer_lock);
	lock.lock();

	//enquanto nao esta vazia
	while(!lista_garrafa_na_mao.empty())
	{
		tmp = lista_garrafa_na_mao.front();
		lista_garrafa_na_mao.pop_front();


		filosofos_da_garrafa = tmp->get_vizinhos();

		//da um sinal para os dois filososfos com a garrafa
		//equivalente a um sinal por garrafa(acho)
		(filosofos_conds_ptrs[filosofos_da_garrafa.first])->notify_one();
		(filosofos_conds_ptrs[filosofos_da_garrafa.second])->notify_one();

		tmp->Devolver();

	}


	lock.unlock();
	return;
}

/*=================================================================//
 * GET: _id
//=================================================================*/

int Filosofo::id()
{
	return _id;
}

/*=================================================================//
 * METODO: Adicionar_garrafa
//=================================================================*/

void Filosofo::Adicionar_garrafa(Garrafa* bottle)
{
	lista_garrafa.push_back(bottle);

}

/*=================================================================//
 * METODO: threadBehavior
//=================================================================*/

void Filosofo::threadBehavior()
{
	//espera ate um iniciaSimulacao
	while(!simulationON());

	unsigned int n_garrafas_desejadas;
	int count;
	duration<double> duracao;


	for(count = 0; count< _num_bebedeiras; count++)
	{
		//Tranquilo------------------------------------------------------
		duracao = Filosofar();
		
		if(DEBUG)
		{//-----------------------------------------------
		mutex_escrita.lock();
		std::cout<<"Filosofo "<<id()<<" Ficou \033[1;34;1mTranquilo\033[0;m por "
				<< duracao.count()<<" segundos"<<endl;
		mutex_escrita.unlock();
		}//-----------------------------------------------

		//Escolhendo num de garrafas------------------------------------ 
		std::random_device generator;
		std::mt19937 mt(generator());
		std::uniform_int_distribution<int> distribution(2,lista_garrafa.size());// 1..n

		n_garrafas_desejadas = distribution(generator);

		if(DEBUG)
		{//------------------------------------------
			mutex_escrita.lock();
			std::cout<<"Filosofo "<<id()<<" num garrafas: "
				<<lista_garrafa.size()<<endl;

			mutex_escrita.unlock();
		}//----------------------------------------------
		//Com sede---------------------------------------------------------
		duracao = Pegar_garrafas(n_garrafas_desejadas);


		if(DEBUG)
		{//-----------------------------------------------
		mutex_escrita.lock();
		std::cout<<"Filosofo "<<id()<<" Ficou com \033[1;33;1mSede\033[0;m de "
				<<n_garrafas_desejadas<<" garrafas, por "
				<< duracao.count()<<" segundos"<<endl;
		mutex_escrita.unlock();
		}//----------------------------------------------



		//Bebendo-----------------------------------------------------------
		duracao = Beber();

		if(DEBUG)
		{//-----------------------------------------------
		mutex_escrita.lock();
		std::cout<<"Filosofo "<<id()<<" \033[1;32;1mBebeu\033[0;m por "
				<< duracao.count()<<" segundos"<<endl;
		mutex_escrita.unlock();
		}//----------------------------------------------


		Retornar_garrafas();
	}
}

/*=================================================================//
 * GET: t_tranquilo
//=================================================================*/

std::chrono::duration<double> Filosofo::t_tranquilo()
{
	return _t_tranquilo;
}

/*=================================================================//
 * GET: t_com_sede
//=================================================================*/

std::chrono::duration<double> Filosofo::t_com_sede()
{
	return _t_com_sede;
}

/*=================================================================//
 * GET: t_bebendo
//=================================================================*/

std::chrono::duration<double> Filosofo::t_bebendo()
{
	return _t_bebendo;
}

/*=================================================================//
 * GET: simulationON
//=================================================================*/

bool Filosofo::simulationON()
{
	return _simulationON;
}

/*=================================================================//
 * METODO: iniciaSimulacao & terminaSimulacao
//=================================================================*/

void Filosofo::iniciaSimulacao()
{
	_simulationON = true; 
}

void Filosofo::terminaSimulacao()
{
	_simulationON = false;
}

/*=================================================================//
 * METODO: printResults
//=================================================================*/

void Filosofo::printResults()
{
	mutex_escrita.lock();
	std::cout<<"|=============================================================================|"<<std::endl;

	std::cout<<" Filosofo "<<id()<<" :"<<std::endl;
	std::cout<<CIANO<<"\tTempo Tranquilo: "<<BRANCO<<t_tranquilo().count()<<std::endl;
	std::cout<<AMARELO<<"\tTempo Com sede: "<<BRANCO<<t_com_sede().count()<<std::endl;
	std::cout<<VERDE<<"\tTempo Bebendo: "<<BRANCO<<t_bebendo().count()<<std::endl;
	std::cout<<MAGENTA<<"\tTempo de espera medio: "<<BRANCO<<(t_com_sede().count())/(_num_bebedeiras*1.0)<<std::endl;
	std::cout<<std::endl;

	mutex_escrita.unlock();
}

/*=================================================================//
 * METODO: retirarGarrafas
//=================================================================*/

void Filosofo::retirarGarrafas(uint ngarafas_retirar)
{
	//retira reservas
	desbloquearGarrafas();

	for(std::list<Garrafa*>::iterator it =lista_garrafa.begin();
		(it != lista_garrafa.end()) && (lista_garrafa_na_mao.size() < ngarafas_retirar)
		; it++)
			{
				if((*it)->disponivel())
				{


					lista_garrafa_na_mao.push_back(*it);
					//retirar garrafa
					(*it)->Retirar();

					if(DEBUG)
					{
						mutex_escrita.lock();
						std::cout<<"\033[1;35;1mFilosofo: "<<id()<<" pegou garrafa "<<(*it)->id()
								<<" ficando com "<<lista_garrafa_na_mao.size()<<"\033[0;m"<<std::endl;

						mutex_escrita.unlock();
					}
				}
			}
	if(lista_garrafa_na_mao.size() < ngarafas_retirar && DEBUG)
	{
		mutex_escrita.lock();
		std::cout<<"\033[1;31;1mFilosofo: "<<id()<<" Queria "<<ngarafas_retirar
				<<" garafas e pegou "<<lista_garrafa_na_mao.size()<<"\033[0;m"<<std::endl;

		mutex_escrita.unlock();
	}

}

/*=================================================================//
 * METODO: reservarGarrafas
//=================================================================*/

void Filosofo::reservarGarrafas()
{
	for(std::list<Garrafa*>::iterator it =lista_garrafa.begin();
				(it != lista_garrafa.end()); it++)
	{
			(*it)->reservar(id());

			if(DEBUG)
			{
				mutex_escrita.lock();
				std::cout<<"\033[1;31;1mFilosofo: "<<id()<<" reservou garrafa "
						<<(*it)->id()<<" reserva: "<<(*it)->reserva()
						<<"\033[0;m"<<std::endl;

				mutex_escrita.unlock();
			}

	}
}

/*=================================================================//
 * METODO: desbloquearGarrafas
//=================================================================*/

void Filosofo::desbloquearGarrafas()
{
	for(std::list<Garrafa*>::iterator it =lista_garrafa.begin();
					(it != lista_garrafa.end()); it++)
		{
				(*it)->removerReserva(id());

				if(DEBUG)
				{
					mutex_escrita.lock();
					std::cout<<"\033[1;33;1mFilosofo: "<<id()<<
							" retirou a reserva da garrafa "
							<<(*it)->id()<<" reserva: "<<(*it)->reserva()
							<<"\033[0;m"<<std::endl;

					mutex_escrita.unlock();
				}

		}
}
//=================================================================//
