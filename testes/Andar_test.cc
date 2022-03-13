#include <gtest/gtest.h>
#include "../inc/Andar.hpp"

TEST(AndarTest, Classe1Instancicao) 
{
    Andar andar;

    EXPECT_EQ(andar.estado_andar(), SEM_PEDIDO);

    Andar andar2;

    EXPECT_NE(andar.num(), andar2.num());
}

TEST(AndarTest, Classe2AtendimentoDeAndar) 
{
    Andar andar;

    andar.atendeuAndar();

    EXPECT_EQ(andar.estado_andar(), SEM_PEDIDO);


}

TEST(AndarTest, Classe3PedidoDescida) 
{
    
    Andar andar;

    andar.setEstadoAndar(SEM_PEDIDO);
    andar.pedidoDescida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESCIDA);

    andar.setEstadoAndar(PEDIDO_SUBIDA);
    andar.pedidoDescida(); 
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);

    andar.setEstadoAndar(PEDIDO_DESCIDA);
    andar.pedidoDescida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESCIDA);

    andar.setEstadoAndar(PEDIDO_DESTINO);
    andar.pedidoDescida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);
}


TEST(AndarTest, Classe4PedidoSubida) 
{
    
    Andar andar;

    andar.setEstadoAndar(SEM_PEDIDO);
    andar.pedidoSubida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_SUBIDA);

    andar.setEstadoAndar(PEDIDO_SUBIDA);
    andar.pedidoSubida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_SUBIDA);

    andar.setEstadoAndar(PEDIDO_DESCIDA);
    andar.pedidoSubida();     
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);

    andar.setEstadoAndar(PEDIDO_DESTINO);
    andar.pedidoSubida();   
    EXPECT_EQ(andar.estado_andar(), PEDIDO_DESTINO);
}


