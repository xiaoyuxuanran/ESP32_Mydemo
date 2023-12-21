# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)


include_directories(${CMAKE_CURRENT._SOURCE_DIR}/components/LED/include)
include_directories(${CMAKE_CURRENT._SOURCE_DIR}/components/uart/include)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(example01)
