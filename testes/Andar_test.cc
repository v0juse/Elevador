#include <gtest/gtest.h>
#include "../inc/Andar.hpp"

TEST(AndarTest, Classe1Instanciacao) 
{
    Andar andar;

    EXPECT_EQ(andar.estado_andar(), SEM_PEDIDO);

    Andar andar2;

    EXPECT_NE(andar.num(), andar2.num());
}
//-------------------------------------------------------------
//                           |    _estado     |    retorno    | 
//---------------------------|----------------|---------------|
// Classe2AtendimentoDeAndar |      A[]       |   SEM_PEDIDO  | 
//-------------------------------------------------------------
TEST(AndarTest, Classe2AtendimentoDeAndar) 
{
    Andar andar;

    andar.atendeuAndar();
  
    EXPECT_EQ(andar.estado_andar(), SEM_PEDIDO);


}
//---------------------------------------------------------
//                      |    _estado     |     retorno    | 
//----------------------|----------------|----------------|
// Classe3PedidoDescida | SEM_PEDIDO     | PEDIDO_DESCIDA | 
// Classe3PedidoDescida | PEDIDO_SUBIDA  | PEDIDO_DESTINO | 
// Classe3PedidoDescida | PEDIDO_DESCIDA | PEDIDO_DESCIDA | 
// Classe3PedidoDescida | PEDIDO_DESTINO | PEDIDO_DESTINO | 
//---------------------------------------------------------
TEST(AndarTest, Classe3PedidoDescida) 
{
    
    Andar andar;

    andar.setEstadoAndar(SEM_PEDIDO);
    andar.pedidoDescida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESCIDA);
    EXPECT_EQ(filaChamadasOrigem.back(), andar.num());

    andar.setEstadoAndar(PEDIDO_SUBIDA);
    andar.pedidoDescida(); 
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);
    EXPECT_EQ(filaChamadasOrigem.back(), andar.num());

    andar.setEstadoAndar(PEDIDO_DESCIDA);
    andar.pedidoDescida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESCIDA);

    andar.setEstadoAndar(PEDIDO_DESTINO);
    andar.pedidoDescida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);
}
//---------------------------------------------------------
//                      |    _estado     |     retorno    | 
//----------------------|----------------|----------------|
// Classe4PedidoSubida | SEM_PEDIDO     | PEDIDO_DESCIDA | 
// Classe4PedidoSubida | PEDIDO_SUBIDA  | PEDIDO_DESTINO | 
// Classe4PedidoSubida | PEDIDO_DESCIDA | PEDIDO_DESCIDA | 
// Classe4PedidoSubida | PEDIDO_DESTINO | PEDIDO_DESTINO | 
//---------------------------------------------------------
TEST(AndarTest, Classe4PedidoSubida) 
{
    Andar andar;

    andar.setEstadoAndar(SEM_PEDIDO);
    andar.pedidoSubida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_SUBIDA);
    EXPECT_EQ(filaChamadasOrigem.back(), andar.num());

    andar.setEstadoAndar(PEDIDO_SUBIDA);
    andar.pedidoSubida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_SUBIDA);
    EXPECT_EQ(filaChamadasOrigem.back(), andar.num());

    andar.setEstadoAndar(PEDIDO_DESCIDA);
    andar.pedidoSubida();     
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);

    andar.setEstadoAndar(PEDIDO_DESTINO);
    andar.pedidoSubida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);
}


TEST(AndarTest, Classe5PedidoDestino) 
{
    Andar andar;

    andar.setEstadoAndar(SEM_PEDIDO);
    andar.pedidoDestino();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);

    andar.setEstadoAndar(PEDIDO_SUBIDA);
    andar.pedidoDestino();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);

    andar.setEstadoAndar(PEDIDO_DESCIDA);
    andar.pedidoDestino();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);

    andar.setEstadoAndar(PEDIDO_DESTINO);
    andar.pedidoDestino();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);
}



