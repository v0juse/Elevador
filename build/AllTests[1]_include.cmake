if(EXISTS "/home/v0id/Faculdade/Testes/Elevador/build/AllTests[1]_tests.cmake")
  include("/home/v0id/Faculdade/Testes/Elevador/build/AllTests[1]_tests.cmake")
else()
  add_test(AllTests_NOT_BUILT AllTests_NOT_BUILT)
endif()
