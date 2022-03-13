#include <gtest/gtest.h>
#include "../inc/SensorPresenca.hpp"

TEST(ValidaIdentificadorTest, Classe_Instanciacao) 
{
    SensorPresencaUsuario user_sensor;
    EXPECT_EQ(user_sensor.numPessoasDentro(), 0);
}

TEST(ValidaIdentificadorTest, Classe_registrarEntrada) 
{
    SensorPresencaUsuario user_sensor;
    user_sensor.registrarEntrada();

    EXPECT_EQ(user_sensor.numPessoasDentro(), 1);
}

TEST(ValidaIdentificadorTest, Classe_registrarSaida) 
{
    SensorPresencaUsuario user_sensor;
    user_sensor.registrarSaida();

    EXPECT_EQ(user_sensor.numPessoasDentro(), 0);
}