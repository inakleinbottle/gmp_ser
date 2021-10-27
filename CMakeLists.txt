cmake_minimum_required(VERSION 3.20)
project(gmp_ser)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-ftemplate-backtrace-limit=0)

find_package(Boost COMPONENTS serialization REQUIRED)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/)
find_package(Bignum)

include(GNUInstallDirs)

add_library(gmp_ser INTERFACE)

target_link_libraries(gmp_ser INTERFACE Boost::boost Boost::serialization Bignum::Bignum)
target_include_directories(gmp_ser INTERFACE
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)

enable_testing()
add_subdirectory(tests)