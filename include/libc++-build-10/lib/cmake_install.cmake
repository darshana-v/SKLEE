# Install script for directory: /home/namrata/libc++-10/llvm/lib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/namrata/libc++-install-10")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/namrata/libc++-build-10/lib/IR/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/FuzzMutate/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/IRReader/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/CodeGen/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/BinaryFormat/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Bitcode/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Bitstream/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/DWARFLinker/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Frontend/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Transforms/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Linker/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Analysis/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/LTO/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/MC/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/MCA/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Object/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/ObjectYAML/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Option/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Remarks/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/DebugInfo/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/ExecutionEngine/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/AsmParser/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/LineEditor/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/ProfileData/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Passes/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/TextAPI/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/ToolDrivers/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/XRay/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Testing/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/WindowsManifest/cmake_install.cmake")

endif()

