#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/Controlador.hpp"

TEST(ControladorTest, Classe1Instancicao) 
{
    EXPECT_STREQ(substring("hamburger", 4), "urger");
    EXPECT_STREQ(substring("batata", 2), "tata");

    EXPECT_STREQ(substring("paralelo", 0), "paralelo");
    EXPECT_STREQ(substring("paralelo", 1), "aralelo");
}
