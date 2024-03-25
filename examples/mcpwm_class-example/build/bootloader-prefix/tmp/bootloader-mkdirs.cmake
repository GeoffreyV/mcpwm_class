# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/vaquettg/esp/v5.2.1/esp-idf/components/bootloader/subproject"
  "D:/mcpwm_class/examples/mcpwm_class-example/build/bootloader"
  "D:/mcpwm_class/examples/mcpwm_class-example/build/bootloader-prefix"
  "D:/mcpwm_class/examples/mcpwm_class-example/build/bootloader-prefix/tmp"
  "D:/mcpwm_class/examples/mcpwm_class-example/build/bootloader-prefix/src/bootloader-stamp"
  "D:/mcpwm_class/examples/mcpwm_class-example/build/bootloader-prefix/src"
  "D:/mcpwm_class/examples/mcpwm_class-example/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/mcpwm_class/examples/mcpwm_class-example/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/mcpwm_class/examples/mcpwm_class-example/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
