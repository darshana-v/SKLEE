# Install script for directory: /home/namrata/libc++-10/llvm/lib/Target

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLLVMTargetx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/namrata/libc++-build-10/lib/libLLVMTarget.a")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/namrata/libc++-build-10/lib/Target/AArch64/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/AMDGPU/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/ARM/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/BPF/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/Hexagon/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/Lanai/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/Mips/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/MSP430/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/NVPTX/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/PowerPC/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/RISCV/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/Sparc/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/SystemZ/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/WebAssembly/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/X86/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Target/XCore/cmake_install.cmake")

endif()

