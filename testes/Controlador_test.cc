#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Controlador.hpp"


/*
namespace testMock
{

    class Porta {
    public:
    Porta(){}
    ~Porta(){}
    // The following 2 lines will not compile due to commas in the arguments:
    MOCK_METHOD(void, abrir, (int num_andar));           
    MOCK_METHOD(void, fechar, (int num_andar));  

    // One solution - wrap arguments that contain commas in parentheses:
    MOCK_METHOD(bool, abertaNoAndar,  (int num));
    };

    class SensorEstadoPorta {
    public:
    SensorEstadoPorta(){}
    ~SensorEstadoPorta(){}
    MOCK_METHOD(bool, objetoBloqueante,());                 
    
    };    


    class SensorAndar {
    public:
    SensorAndar(){}    
    ~SensorAndar(){}
    MOCK_METHOD(bool, andarAlcancado,());            

    };

    class Andar
    {
    public:
        
    };

}*/

//================================================================================//

class mockPorta: public Porta {
    public:
    mockPorta(){}
    ~mockPorta(){}

    MOCK_METHOD(void, abrir, (int num_andar));           
    MOCK_METHOD(void, fechar, (int num_andar));  

    // One solution - wrap arguments that contain commas in parentheses:
    MOCK_METHOD(bool, abertaNoAndar,  (int num));
    };

class mockSensorEstadoPorta: public SensorEstadoPorta {
    public:
    mockSensorEstadoPorta(){}
    ~mockSensorEstadoPorta(){}
    MOCK_METHOD(bool, objetoBloqueante,());                 
    
    };    


class mockSensorAndar: public SensorAndar{
    public:
    mockSensorAndar(){}    
    ~mockSensorAndar(){}
    MOCK_METHOD(bool, andarAlcancado,());            

    };

class mockAndar: public Andar{
    public:
    
    MOCK_METHOD(bool, andarAlcancado,());            
    };



//================================================================================//



TEST(ControladorTest, Classe0Instanciacao) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
    
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);

    EXPECT_EQ(controller.get_andarObjetivo(), -1);
    EXPECT_EQ(controller.get_andarAtual(), 0);
   
    EXPECT_FALSE(controller.get_movimento());
    EXPECT_FALSE(controller.get_tratandoOrigem());

    controller.join();
}

// Classe1cond_abertura_porta | Estado_andar PEDIDO_DESTINO     && A[] direcao    | true |
// Classe2cond_abertura_porta | Estado_andar PEDIDO_SUBIDA      && direcao != -1  | true |
// Classe3cond_abertura_porta | Estado_andar PEDIDO_SUBIDA      && direcao == -1  | false|  
// Classe4cond_abertura_porta | Estado_andar PEDIDO_DESCIDA     && direcao !=  1  | true |
// Classe5cond_abertura_porta | Estado_andar PEDIDO_DESCIDA     && direcao == 1  | false|
// Classe6cond_abertura_porta | Estado_andar != SEM_PEDIDO      && direcao == 0   | true | 
// Classe7cond_abertura_porta | Estado_andar == SEM_PEDIDO      && A[] direcao    | false| 
 


// Classe1cond_abertura_porta | Estado_andar PEDIDO_DESTINO     && A[] direcao    | true |
TEST(ControladorTest, Classe1cond_abertura_porta) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
    
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
    
    vetorAndares[controller.get_andarAtual()].setEstadoAndar(PEDIDO_DESTINO);
    direcao = -1;
    EXPECT_TRUE(controller.cond_abertura_porta());
    
    vetorAndares[controller.get_andarAtual()].setEstadoAndar(PEDIDO_DESTINO);
    direcao = 0;
    EXPECT_TRUE(controller.cond_abertura_porta());

    vetorAndares[controller.get_andarAtual()].setEstadoAndar(PEDIDO_DESTINO);
    direcao = 1;
    EXPECT_TRUE(controller.cond_abertura_porta());

    controller.join();

}

// Classe2cond_abertura_porta | Estado_andar PEDIDO_SUBIDA      && direcao != -1  | true |
TEST(ControladorTest, Classe2cond_abertura_porta) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
      
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
    
    vetorAndares[controller.get_andarAtual()].setEstadoAndar(PEDIDO_SUBIDA);
    direcao = 0;
    EXPECT_TRUE(controller.cond_abertura_porta());

    vetorAndares[controller.get_andarAtual()].setEstadoAndar(PEDIDO_SUBIDA);
    direcao = 1;
    EXPECT_TRUE(controller.cond_abertura_porta());
    
    controller.join();
}
// Classe3cond_abertura_porta | Estado_andar PEDIDO_SUBIDA      && direcao == -1  | false|  
TEST(ControladorTest, Classe3cond_abertura_porta) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
    
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
    
    vetorAndares[controller.get_andarAtual()].setEstadoAndar(PEDIDO_SUBIDA);
    direcao = -1;
    EXPECT_FALSE(controller.cond_abertura_porta());    

    controller.join();

}


// Classe4cond_abertura_porta | Estado_andar PEDIDO_DESCIDA     && direcao !=  1  | true |
TEST(ControladorTest, Classe4cond_abertura_porta) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
      
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
    
    vetorAndares[controller.get_andarAtual()].setEstadoAndar(PEDIDO_DESCIDA);
    direcao = 0;
    EXPECT_TRUE(controller.cond_abertura_porta());

    vetorAndares[controller.get_andarAtual()].setEstadoAndar(PEDIDO_DESCIDA);
    direcao = -1;
    EXPECT_TRUE(controller.cond_abertura_porta());
    
    controller.join();

}


// Classe5cond_abertura_porta | Estado_andar PEDIDO_DESCIDA     && direcao == 1  | false|
TEST(ControladorTest, Classe5cond_abertura_porta) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
    
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
 

    vetorAndares[controller.get_andarAtual()].setEstadoAndar(PEDIDO_DESCIDA);
    direcao = 1;
    EXPECT_FALSE(controller.cond_abertura_porta());    

    controller.join();
}


// Classe6cond_abertura_porta | Estado_andar != SEM_PEDIDO      && direcao == 0   | true |

TEST(ControladorTest, Classe6cond_abertura_porta) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
      
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
    
    vetorAndares[controller.get_andarAtual()].setEstadoAndar(PEDIDO_SUBIDA);
    direcao = 0;
    EXPECT_TRUE(controller.cond_abertura_porta());

    vetorAndares[controller.get_andarAtual()].setEstadoAndar(PEDIDO_DESCIDA);
    direcao = 0;  
    EXPECT_TRUE(controller.cond_abertura_porta());

    

    
    controller.join();
}

// Classe7cond_abertura_porta | Estado_andar == SEM_PEDIDO      && A[] direcao    | false| 
TEST(ControladorTest, Classe7cond_abertura_porta) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
    
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
    
    vetorAndares[controller.get_andarAtual()].setEstadoAndar(SEM_PEDIDO);
    direcao = -1;
    EXPECT_FALSE(controller.cond_abertura_porta());
    
    vetorAndares[controller.get_andarAtual()].setEstadoAndar(SEM_PEDIDO);
    direcao = 0;
    EXPECT_FALSE(controller.cond_abertura_porta());

    vetorAndares[controller.get_andarAtual()].setEstadoAndar(SEM_PEDIDO);
    direcao = 1;
    EXPECT_FALSE(controller.cond_abertura_porta());          
  
    controller.join();
}


// Classe8def_direcao  | andarAtual = andarObjetivo  | direcao =  0| 
// Classe9def_direcao  | andarAtual > andarObjetivo  | direcao = -1|
// Classe10def_direcao | andarAtual < andarObjetivo  | direcao =  1|
 
TEST(ControladorTest, Classe8def_direcao)     
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
    
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
    
    controller.set_andarAtual(3);
    controller.set_andarObjetivo(3);

    controller.def_direcao();
    EXPECT_EQ(direcao, 0);           
  
    controller.join();
} 

TEST(ControladorTest, Classe9def_direcao) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
    
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
    
    controller.set_andarAtual(3);
    controller.set_andarObjetivo(0);     
 
    controller.def_direcao();
    EXPECT_EQ(direcao, -1);          
  
    controller.join();
} 

TEST(ControladorTest, Classe10def_direcao ) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
    
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
    
    controller.set_andarAtual(0);
    controller.set_andarObjetivo(numAndares);

    controller.def_direcao();
    EXPECT_EQ(direcao, 1);          
  
    controller.join();
} 

// Classe11atendeu_andar | andarAtual == andarObjetivo  | andarObjetivo =  -1| 
// Classe12atendeu_andar | andarAtual != andarObjetivo  | andarObjetivo = cte|


TEST(ControladorTest, Classe11atendeu_andar ) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
    
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
    
    controller.set_andarAtual(0);
    controller.set_andarObjetivo(0);

    controller.atendeu_andar();
    EXPECT_EQ(controller.get_andarObjetivo(), -1);  

    controller.set_andarAtual(numAndares);
    controller.set_andarObjetivo(numAndares);

    controller.atendeu_andar();
    EXPECT_EQ(controller.get_andarObjetivo(), -1);          
          
  
    controller.join();
} 

TEST(ControladorTest, Classe12atendeu_andar ) 
{   
    mockPorta mock_door;
    mockSensorEstadoPorta mock_sensor_door;
    mockSensorAndar mock_sensor_andar;
    
    Controlador controller(&mock_door, &mock_sensor_door, &mock_sensor_andar, true);
    
    controller.set_andarAtual(0);
    controller.set_andarObjetivo(numAndares);

    controller.def_direcao();
    EXPECT_EQ(controller.get_andarObjetivo(), numAndares);          
  
    controller.join();
} 


