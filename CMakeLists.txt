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


enable_testing()
message("PROJECT_SOURCE_DIR points to " ${PROJECT_SOURCE_DIR})
#add_executable(hello_test  hello_test.cc soma.cc)
#target_link_libraries(hello_test  gtest_main)
include_directories(${INC_DIR})
add_library(utility ${SRC_DIR}/Utility.cpp)

add_executable(AndarTest ${SRC_DIR}/Andar.cpp ${SRC_DIR}/Utility.cpp ${TEST_DIR}/Andar_test.cc)
target_link_libraries(AndarTest gtest_main)

#add_executable(controlador_valido Controlador.cpp Controlador_test.cc)
#target_link_libraries(controlador_valido  gtest_main)

add_executable(PortaTest ${SRC_DIR}/Porta.cpp ${TEST_DIR}/Porta_test.cc)
target_link_libraries(PortaTest  gtest_main)

add_executable(SensorAndar ${SRC_DIR}/SensorAndar.cpp Andar_test.cc)
target_link_libraries(andar_valido  gtest_main)

# add_executable(andar_valido Andar.cpp Andar_test.cc)
# target_link_libraries(andar_valido  gtest_main)

# add_executable(andar_valido Andar.cpp Andar_test.cc)
# target_link_libraries(andar_valido  gtest_main)

# add_executable(andar_valido Andar.cpp Andar_test.cc)
# target_link_libraries(andar_valido  gtest_main)

# add_executable(andar_valido Andar.cpp Andar_test.cc)
# target_link_libraries(andar_valido  gtest_main)

# add_executable(andar_valido Andar.cpp Andar_test.cc)
# target_link_libraries(andar_valido  gtest_main)

#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;--header-filter=.; --checks=*;")

include(GoogleTest)
gtest_discover_tests(AndarTest PortaTest)