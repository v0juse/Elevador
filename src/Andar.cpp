#include "Andar.hpp"

_num_andares = 0;

    Andar::Andar()
    {
        _num = _num_andares++;
        _estado = SEM_PEDIDO;
    }
    Andar::~Andar()
    {
        _num_andares--;
    }

    enum ESTADOS_ANDAR Andar::estado_andar()
    {
        return _estado
    }
