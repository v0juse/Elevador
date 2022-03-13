#include <gtest/gtest.h>
#include "../inc/Controlador.hpp"

TEST(ControladorTest, Classe1) 
{
    EXPECT_STREQ(substring("hamburger", 4), "urger");
    EXPECT_STREQ(substring("batata", 2), "tata");

    EXPECT_STREQ(substring("paralelo", 0), "paralelo");
    EXPECT_STREQ(substring("paralelo", 1), "aralelo");
}
