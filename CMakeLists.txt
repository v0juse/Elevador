cmake_minimum_required(VERSION 3.14)
SET(PROJ_NAME "Elevador_Simulacao")
PROJECT(${PROJ_NAME})

#project(gtestproj)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Paths
SET(INC_DIR ${PROJECT_SOURCE_DIR}/inc)
SET(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
SET(TEST_DIR ${PROJECT_SOURCE_DIR}/testes)
set( CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage -std=c++11 ${CMAKE_CXX_FLAGS}" )

enable_testing()
message("PROJECT_SOURCE_DIR points to " ${PROJECT_SOURCE_DIR})
#add_executable(hello_test  hello_test.cc soma.cc)
#target_link_libraries(hello_test  gtest_main)
include_directories(${INC_DIR})
add_library(utility ${SRC_DIR}/Utility.cpp)

add_executable(AndarTest ${SRC_DIR}/Andar.cpp  ${TEST_DIR}/Andar_test.cc)
target_link_libraries(AndarTest gtest_main utility)

#add_executable(controlador_valido Controlador.cpp Controlador_test.cc)
#target_link_libraries(controlador_valido  gtest_main)

add_executable(PortaTest ${SRC_DIR}/Porta.cpp ${TEST_DIR}/Porta_test.cc)
target_link_libraries(PortaTest  gtest_main utility)

add_executable(SensorAndarTest ${SRC_DIR}/SensorAndar.cpp ${TEST_DIR}/SensorAndar_test.cc)
target_link_libraries(SensorAndarTest  gtest_main utility)

add_executable(SensorPresencaTest ${SRC_DIR}/SensorPresenca.cpp ${TEST_DIR}/SensorPresenca_test.cc)
target_link_libraries(SensorPresencaTest  gtest_main utility)

add_executable(ControladorTest ${TEST_DIR}/Controlador_test.cc ${SRC_DIR}/Controlador.cpp  ${SRC_DIR}/Andar.cpp  ${SRC_DIR}/SensorAndar.cpp ${SRC_DIR}/SensorPresenca.cpp ${SRC_DIR}/Porta.cpp ${SRC_DIR}/SensorEstadoPorta.cpp)
target_link_libraries(ControladorTest  gtest_main gmock_main utility)



#add_executable(ElevadorSimulacao ${SRC_DIR}/*)
#target_link_libraries(ElevadorSimulacao)


# add_executable(andar_valido Andar.cpp Andar_test.cc)
# target_link_libraries(andar_valido  gtest_main)

# add_executable(andar_valido Andar.cpp Andar_test.cc)
# target_link_libraries(andar_valido  gtest_main)

# add_executable(andar_valido Andar.cpp Andar_test.cc)
# target_link_libraries(andar_valido  gtest_main)

#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;--header-filter=.; --checks=*;")

include(GoogleTest)
gtest_discover_tests(AndarTest PortaTest SensorAndarTest SensorPresencaTest ControladorTest)