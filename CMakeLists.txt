cmake_minimum_required(VERSION 3.14)
project(gtestproj)

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

enable_testing()

#add_executable(hello_test  hello_test.cc soma.cc)
#target_link_libraries(hello_test  gtest_main)

add_executable(AndarTest Andar.cpp Andar_test.cc)
target_link_libraries(AndarTest  gtest_main)

# add_executable(controlador_valido Controlador.cpp Controlador_test.cc)
# target_link_libraries(controlador_valido  gtest_main)

# add_executable(Porta_valido Porta.cpp Porta_test.cc)
# target_link_libraries(Porta_valido  gtest_main)

# add_executable(Sensor_valido Andar.cpp Andar_test.cc)
# target_link_libraries(andar_valido  gtest_main)

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
gtest_discover_tests(andar_valido)