cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(Threads REQUIRED)

configure_file(version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version.h)

add_executable(helloworld main.cpp)
add_executable(helloworld_test_cli test_main.cpp)

add_library(helloworld_lib lib.cpp)

set_target_properties(helloworld_lib helloworld helloworld_test_cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(helloworld_test_cli PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(helloworld ${CMAKE_THREAD_LIBS_INIT} helloworld_lib)
target_link_libraries(helloworld_test_cli ${Boost_LIBRARIES} helloworld_lib)

install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT stillarty@ya.ru)

include (CPack)

enable_testing()

add_test(test_version_valid helloworld_test_cli)
