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

# Utility rule file for llvm-libraries.

# Include the progress variables for this target.
include CMakeFiles/llvm-libraries.dir/progress.make

llvm-libraries: CMakeFiles/llvm-libraries.dir/build.make

.PHONY : llvm-libraries

# Rule to build all files generated by this target.
CMakeFiles/llvm-libraries.dir/build: llvm-libraries

.PHONY : CMakeFiles/llvm-libraries.dir/build

CMakeFiles/llvm-libraries.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/llvm-libraries.dir/cmake_clean.cmake
.PHONY : CMakeFiles/llvm-libraries.dir/clean

CMakeFiles/llvm-libraries.dir/depend:
	cd /home/namrata/libc++-build-10 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/namrata/libc++-10/llvm /home/namrata/libc++-10/llvm /home/namrata/libc++-build-10 /home/namrata/libc++-build-10 /home/namrata/libc++-build-10/CMakeFiles/llvm-libraries.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/llvm-libraries.dir/depend
