#include <gtest/gtest.h>
#include "valida_identificador.h"

TEST(ValidaIdentificadorTest, Classe1) {
  EXPECT_TRUE(valida_identificador("ab12345"));
}

TEST(ValidaIdentificadorTest, Classe2) {
  EXPECT_FALSE(valida_identificador("sah12^*&^"));
}

TEST(ValidaIdentificadorTest, Classe3) {
  EXPECT_TRUE(valida_identificador("abcdefgh"));
  EXPECT_TRUE(valida_identificador("ab2"));
  EXPECT_TRUE(valida_identificador("ab2b"));
  EXPECT_TRUE(valida_identificador("ABCDE123456789"));
  EXPECT_TRUE(valida_identificador("ABCDE1234567890"));
}

TEST(ValidaIdentificadorTest, Classe4) {
  EXPECT_FALSE(valida_identificador("AA"));
}

TEST(ValidaIdentificadorTest, Classe5) {
  EXPECT_FALSE(valida_identificador("ABCDE123345678901234567890"));
  EXPECT_FALSE(valida_identificador("ABCDE12345678901"));
}

TEST(ValidaIdentificadorTest, Classe6) {
  EXPECT_TRUE(valida_identificador("ab123123"));
}

TEST(ValidaIdentificadorTest, Classe7) {
  EXPECT_FALSE(valida_identificador("1asd"));
}