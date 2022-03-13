#include <gtest/gtest.h>
#include "../inc/Porta.hpp"

TEST(ValidaIdentificadorTest, Classe1) 
{
    EXPECT_STREQ(substring("hamburger", 4), "urger");
    EXPECT_STREQ(substring("batata", 2), "tata");

    EXPECT_STREQ(substring("paralelo", 0), "paralelo");
    EXPECT_STREQ(substring("paralelo", 1), "aralelo");
}