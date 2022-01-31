#ifndef ANDAR_HPP_
#define ANDAR_HPP_

enum ESTADOS_ANDAR{SEM_PEDIDO, PEDIDO_SUBIDA, PEDIDO_DESCIDA, PEDIDO_DESTINO};



class Andar
{
public:
    Andar();
    ~Andar();

    enum ESTADOS_ANDAR estado_andar();

    
private:
    int _num;
    static int _num_andares;
    enum ESTADOS_ANDAR _estado;

}







#endif