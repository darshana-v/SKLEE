# Install script for directory: /home/namrata/libc++-10/llvm/unittests

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
  include("/home/namrata/libc++-build-10/unittests/ADT/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Analysis/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/AsmParser/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/BinaryFormat/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Bitcode/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Bitstream/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/CodeGen/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/DebugInfo/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Demangle/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/ExecutionEngine/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Frontend/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/FuzzMutate/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/IR/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/LineEditor/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Linker/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/MC/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/MI/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Object/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/ObjectYAML/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Option/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Remarks/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Passes/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/ProfileData/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Support/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/TableGen/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Target/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/TextAPI/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/Transforms/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/XRay/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/tools/cmake_install.cmake")

endif()

