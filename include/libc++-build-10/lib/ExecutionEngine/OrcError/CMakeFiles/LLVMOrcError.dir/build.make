# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/namrata/libc++-10/llvm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/namrata/libc++-build-10

# Include any dependencies generated for this target.
include lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/depend.make

# Include the progress variables for this target.
include lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/progress.make

# Include the compile flags for this target's objects.
include lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/flags.make

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/flags.make
lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o: /home/namrata/libc++-10/llvm/lib/ExecutionEngine/OrcError/OrcError.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o"
	cd /home/namrata/libc++-build-10/lib/ExecutionEngine/OrcError && /usr/local/bin/wllvm++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o -c /home/namrata/libc++-10/llvm/lib/ExecutionEngine/OrcError/OrcError.cpp

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMOrcError.dir/OrcError.cpp.i"
	cd /home/namrata/libc++-build-10/lib/ExecutionEngine/OrcError && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/namrata/libc++-10/llvm/lib/ExecutionEngine/OrcError/OrcError.cpp > CMakeFiles/LLVMOrcError.dir/OrcError.cpp.i

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMOrcError.dir/OrcError.cpp.s"
	cd /home/namrata/libc++-build-10/lib/ExecutionEngine/OrcError && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/namrata/libc++-10/llvm/lib/ExecutionEngine/OrcError/OrcError.cpp -o CMakeFiles/LLVMOrcError.dir/OrcError.cpp.s

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o.requires:

.PHONY : lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o.requires

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o.provides: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o.requires
	$(MAKE) -f lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/build.make lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o.provides.build
.PHONY : lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o.provides

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o.provides.build: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o


lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/flags.make
lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o: /home/namrata/libc++-10/llvm/lib/ExecutionEngine/OrcError/RPCError.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o"
	cd /home/namrata/libc++-build-10/lib/ExecutionEngine/OrcError && /usr/local/bin/wllvm++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o -c /home/namrata/libc++-10/llvm/lib/ExecutionEngine/OrcError/RPCError.cpp

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMOrcError.dir/RPCError.cpp.i"
	cd /home/namrata/libc++-build-10/lib/ExecutionEngine/OrcError && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/namrata/libc++-10/llvm/lib/ExecutionEngine/OrcError/RPCError.cpp > CMakeFiles/LLVMOrcError.dir/RPCError.cpp.i

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMOrcError.dir/RPCError.cpp.s"
	cd /home/namrata/libc++-build-10/lib/ExecutionEngine/OrcError && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/namrata/libc++-10/llvm/lib/ExecutionEngine/OrcError/RPCError.cpp -o CMakeFiles/LLVMOrcError.dir/RPCError.cpp.s

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o.requires:

.PHONY : lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o.requires

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o.provides: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o.requires
	$(MAKE) -f lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/build.make lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o.provides.build
.PHONY : lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o.provides

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o.provides.build: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o


# Object files for target LLVMOrcError
LLVMOrcError_OBJECTS = \
"CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o" \
"CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o"

# External object files for target LLVMOrcError
LLVMOrcError_EXTERNAL_OBJECTS =

lib/libLLVMOrcError.a: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o
lib/libLLVMOrcError.a: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o
lib/libLLVMOrcError.a: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/build.make
lib/libLLVMOrcError.a: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../libLLVMOrcError.a"
	cd /home/namrata/libc++-build-10/lib/ExecutionEngine/OrcError && $(CMAKE_COMMAND) -P CMakeFiles/LLVMOrcError.dir/cmake_clean_target.cmake
	cd /home/namrata/libc++-build-10/lib/ExecutionEngine/OrcError && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LLVMOrcError.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/build: lib/libLLVMOrcError.a

.PHONY : lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/build

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/requires: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/OrcError.cpp.o.requires
lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/requires: lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/RPCError.cpp.o.requires

.PHONY : lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/requires

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/clean:
	cd /home/namrata/libc++-build-10/lib/ExecutionEngine/OrcError && $(CMAKE_COMMAND) -P CMakeFiles/LLVMOrcError.dir/cmake_clean.cmake
.PHONY : lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/clean

lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/depend:
	cd /home/namrata/libc++-build-10 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/namrata/libc++-10/llvm /home/namrata/libc++-10/llvm/lib/ExecutionEngine/OrcError /home/namrata/libc++-build-10 /home/namrata/libc++-build-10/lib/ExecutionEngine/OrcError /home/namrata/libc++-build-10/lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/ExecutionEngine/OrcError/CMakeFiles/LLVMOrcError.dir/depend
