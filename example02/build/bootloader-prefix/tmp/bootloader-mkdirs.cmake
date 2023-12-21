# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Espressif/frameworks/esp-idf-v5.1.2/components/bootloader/subproject"
  "E:/new_code/demo01/example01/build/bootloader"
  "E:/new_code/demo01/example01/build/bootloader-prefix"
  "E:/new_code/demo01/example01/build/bootloader-prefix/tmp"
  "E:/new_code/demo01/example01/build/bootloader-prefix/src/bootloader-stamp"
  "E:/new_code/demo01/example01/build/bootloader-prefix/src"
  "E:/new_code/demo01/example01/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/new_code/demo01/example01/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/new_code/demo01/example01/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
