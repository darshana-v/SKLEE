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

# Utility rule file for install-llvm-rc.

# Include the progress variables for this target.
include tools/llvm-rc/CMakeFiles/install-llvm-rc.dir/progress.make

tools/llvm-rc/CMakeFiles/install-llvm-rc:
	cd /home/namrata/libc++-build-10/tools/llvm-rc && /usr/bin/cmake -DCMAKE_INSTALL_COMPONENT="llvm-rc" -P /home/namrata/libc++-build-10/cmake_install.cmake

install-llvm-rc: tools/llvm-rc/CMakeFiles/install-llvm-rc
install-llvm-rc: tools/llvm-rc/CMakeFiles/install-llvm-rc.dir/build.make

.PHONY : install-llvm-rc

# Rule to build all files generated by this target.
tools/llvm-rc/CMakeFiles/install-llvm-rc.dir/build: install-llvm-rc

.PHONY : tools/llvm-rc/CMakeFiles/install-llvm-rc.dir/build

tools/llvm-rc/CMakeFiles/install-llvm-rc.dir/clean:
	cd /home/namrata/libc++-build-10/tools/llvm-rc && $(CMAKE_COMMAND) -P CMakeFiles/install-llvm-rc.dir/cmake_clean.cmake
.PHONY : tools/llvm-rc/CMakeFiles/install-llvm-rc.dir/clean

tools/llvm-rc/CMakeFiles/install-llvm-rc.dir/depend:
	cd /home/namrata/libc++-build-10 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/namrata/libc++-10/llvm /home/namrata/libc++-10/llvm/tools/llvm-rc /home/namrata/libc++-build-10 /home/namrata/libc++-build-10/tools/llvm-rc /home/namrata/libc++-build-10/tools/llvm-rc/CMakeFiles/install-llvm-rc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/llvm-rc/CMakeFiles/install-llvm-rc.dir/depend
