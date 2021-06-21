# Install script for directory: /home/namrata/libc++-10/llvm

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xllvm-headersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES
    "/home/namrata/libc++-10/llvm/include/llvm"
    "/home/namrata/libc++-10/llvm/include/llvm-c"
    FILES_MATCHING REGEX "/[^/]*\\.def$" REGEX "/[^/]*\\.h$" REGEX "/[^/]*\\.td$" REGEX "/[^/]*\\.inc$" REGEX "/LICENSE\\.TXT$" REGEX "/\\.svn$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xllvm-headersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES
    "/home/namrata/libc++-build-10/include/llvm"
    "/home/namrata/libc++-build-10/include/llvm-c"
    FILES_MATCHING REGEX "/[^/]*\\.def$" REGEX "/[^/]*\\.h$" REGEX "/[^/]*\\.gen$" REGEX "/[^/]*\\.inc$" REGEX "/CMakeFiles$" EXCLUDE REGEX "/config\\.h$" EXCLUDE REGEX "/\\.svn$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/namrata/libc++-build-10/lib/Demangle/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/Support/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/TableGen/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/utils/TableGen/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/include/llvm/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/lib/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/utils/FileCheck/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/utils/PerfectShuffle/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/utils/count/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/utils/not/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/utils/yaml-bench/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/projects/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/tools/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/runtimes/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/examples/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/utils/lit/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/test/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/unittests/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/utils/unittest/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/docs/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/cmake/modules/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/utils/llvm-lit/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/utils/benchmark/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/benchmarks/cmake_install.cmake")
  include("/home/namrata/libc++-build-10/utils/llvm-locstats/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/namrata/libc++-build-10/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
