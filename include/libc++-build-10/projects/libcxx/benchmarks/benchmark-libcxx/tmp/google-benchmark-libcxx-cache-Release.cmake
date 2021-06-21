
set(CMAKE_C_COMPILER "/usr/local/bin/wllvm" CACHE STRING "Initial cache" FORCE)
set(CMAKE_CXX_COMPILER "/usr/local/bin/wllvm++" CACHE STRING "Initial cache" FORCE)
set(CMAKE_BUILD_TYPE "RELEASE" CACHE STRING "Initial cache" FORCE)
set(CMAKE_INSTALL_PREFIX "/home/namrata/libc++-build-10/projects/libcxx/benchmarks/benchmark-libcxx" CACHE PATH "Initial cache" FORCE)
set(CMAKE_CXX_FLAGS "-Wno-unused-command-line-argument -nostdinc++ -isystem /home/namrata/libc++-10/llvm/projects/libcxx/include -L/home/namrata/libc++-build-10/./lib -Wl,-rpath,/home/namrata/libc++-build-10/./lib -L -Wl,-rpath, -include /home/namrata/libc++-build-10/projects/libcxx/__config_site" CACHE STRING "Initial cache" FORCE)
set(BENCHMARK_USE_LIBCXX "ON" CACHE BOOL "Initial cache" FORCE)
set(BENCHMARK_ENABLE_TESTING "OFF" CACHE BOOL "Initial cache" FORCE)