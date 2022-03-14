#include <gtest/gtest.h>
#include "../inc/Porta.hpp"

TEST(PortaTest, Classe1Instancicao) 
{
    Porta door;

    for(auto i=0; i < numAndares; ++i)
        EXPECT_FALSE(door.abertaNoAndar(i));
}

TEST(PortaTest, Classe2Abrir) 
{
    Porta door;

    for(auto i=0; i < numAndares; ++i)
    {
        door.abrir(i);
        EXPECT_TRUE(door.abertaNoAndar(i));
    }
}

TEST(PortaTest, Classe3Fechar) 
{
    Porta door;

    for(auto i=0; i < numAndares; ++i)
    {
        door.fechar(i);
        EXPECT_FALSE(door.abertaNoAndar(i));
    }
}