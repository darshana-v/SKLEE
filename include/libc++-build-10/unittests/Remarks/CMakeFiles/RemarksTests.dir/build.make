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
include unittests/Remarks/CMakeFiles/RemarksTests.dir/depend.make

# Include the progress variables for this target.
include unittests/Remarks/CMakeFiles/RemarksTests.dir/progress.make

# Include the compile flags for this target's objects.
include unittests/Remarks/CMakeFiles/RemarksTests.dir/flags.make

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o: unittests/Remarks/CMakeFiles/RemarksTests.dir/flags.make
unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o: /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksFormatTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o -c /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksFormatTest.cpp

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.i"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksFormatTest.cpp > CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.i

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.s"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksFormatTest.cpp -o CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.s

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o.requires:

.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o.requires

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o.provides: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o.requires
	$(MAKE) -f unittests/Remarks/CMakeFiles/RemarksTests.dir/build.make unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o.provides.build
.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o.provides

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o.provides.build: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o


unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o: unittests/Remarks/CMakeFiles/RemarksTests.dir/flags.make
unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o: /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksParsingTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o -c /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksParsingTest.cpp

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.i"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksParsingTest.cpp > CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.i

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.s"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksParsingTest.cpp -o CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.s

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o.requires:

.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o.requires

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o.provides: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o.requires
	$(MAKE) -f unittests/Remarks/CMakeFiles/RemarksTests.dir/build.make unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o.provides.build
.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o.provides

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o.provides.build: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o


unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o: unittests/Remarks/CMakeFiles/RemarksTests.dir/flags.make
unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o: /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksSerializerTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o -c /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksSerializerTest.cpp

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.i"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksSerializerTest.cpp > CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.i

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.s"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/namrata/libc++-10/llvm/unittests/Remarks/BitstreamRemarksSerializerTest.cpp -o CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.s

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o.requires:

.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o.requires

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o.provides: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o.requires
	$(MAKE) -f unittests/Remarks/CMakeFiles/RemarksTests.dir/build.make unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o.provides.build
.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o.provides

unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o.provides.build: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o


unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o: unittests/Remarks/CMakeFiles/RemarksTests.dir/flags.make
unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o: /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksAPITest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o -c /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksAPITest.cpp

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.i"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksAPITest.cpp > CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.i

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.s"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksAPITest.cpp -o CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.s

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o.requires:

.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o.requires

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o.provides: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o.requires
	$(MAKE) -f unittests/Remarks/CMakeFiles/RemarksTests.dir/build.make unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o.provides.build
.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o.provides

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o.provides.build: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o


unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o: unittests/Remarks/CMakeFiles/RemarksTests.dir/flags.make
unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o: /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksLinkingTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o -c /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksLinkingTest.cpp

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.i"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksLinkingTest.cpp > CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.i

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.s"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksLinkingTest.cpp -o CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.s

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o.requires:

.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o.requires

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o.provides: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o.requires
	$(MAKE) -f unittests/Remarks/CMakeFiles/RemarksTests.dir/build.make unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o.provides.build
.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o.provides

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o.provides.build: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o


unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o: unittests/Remarks/CMakeFiles/RemarksTests.dir/flags.make
unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o: /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksStrTabParsingTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o -c /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksStrTabParsingTest.cpp

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.i"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksStrTabParsingTest.cpp > CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.i

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.s"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/namrata/libc++-10/llvm/unittests/Remarks/RemarksStrTabParsingTest.cpp -o CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.s

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o.requires:

.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o.requires

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o.provides: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o.requires
	$(MAKE) -f unittests/Remarks/CMakeFiles/RemarksTests.dir/build.make unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o.provides.build
.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o.provides

unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o.provides.build: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o


unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o: unittests/Remarks/CMakeFiles/RemarksTests.dir/flags.make
unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o: /home/namrata/libc++-10/llvm/unittests/Remarks/YAMLRemarksParsingTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o -c /home/namrata/libc++-10/llvm/unittests/Remarks/YAMLRemarksParsingTest.cpp

unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.i"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/namrata/libc++-10/llvm/unittests/Remarks/YAMLRemarksParsingTest.cpp > CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.i

unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.s"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/namrata/libc++-10/llvm/unittests/Remarks/YAMLRemarksParsingTest.cpp -o CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.s

unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o.requires:

.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o.requires

unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o.provides: unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o.requires
	$(MAKE) -f unittests/Remarks/CMakeFiles/RemarksTests.dir/build.make unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o.provides.build
.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o.provides

unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o.provides.build: unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o


unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o: unittests/Remarks/CMakeFiles/RemarksTests.dir/flags.make
unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o: /home/namrata/libc++-10/llvm/unittests/Remarks/YAMLRemarksSerializerTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o -c /home/namrata/libc++-10/llvm/unittests/Remarks/YAMLRemarksSerializerTest.cpp

unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.i"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/namrata/libc++-10/llvm/unittests/Remarks/YAMLRemarksSerializerTest.cpp > CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.i

unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.s"
	cd /home/namrata/libc++-build-10/unittests/Remarks && /usr/local/bin/wllvm++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/namrata/libc++-10/llvm/unittests/Remarks/YAMLRemarksSerializerTest.cpp -o CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.s

unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o.requires:

.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o.requires

unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o.provides: unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o.requires
	$(MAKE) -f unittests/Remarks/CMakeFiles/RemarksTests.dir/build.make unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o.provides.build
.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o.provides

unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o.provides.build: unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o


# Object files for target RemarksTests
RemarksTests_OBJECTS = \
"CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o" \
"CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o" \
"CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o" \
"CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o" \
"CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o" \
"CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o" \
"CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o" \
"CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o"

# External object files for target RemarksTests
RemarksTests_EXTERNAL_OBJECTS =

unittests/Remarks/RemarksTests: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o
unittests/Remarks/RemarksTests: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o
unittests/Remarks/RemarksTests: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o
unittests/Remarks/RemarksTests: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o
unittests/Remarks/RemarksTests: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o
unittests/Remarks/RemarksTests: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o
unittests/Remarks/RemarksTests: unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o
unittests/Remarks/RemarksTests: unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o
unittests/Remarks/RemarksTests: unittests/Remarks/CMakeFiles/RemarksTests.dir/build.make
unittests/Remarks/RemarksTests: lib/libLLVMBitReader.a
unittests/Remarks/RemarksTests: lib/libLLVMRemarks.a
unittests/Remarks/RemarksTests: lib/libLLVMSupport.a
unittests/Remarks/RemarksTests: lib/libLLVMSupport.a
unittests/Remarks/RemarksTests: lib/libgtest_main.a
unittests/Remarks/RemarksTests: lib/libgtest.a
unittests/Remarks/RemarksTests: lib/libLLVMCore.a
unittests/Remarks/RemarksTests: lib/libLLVMRemarks.a
unittests/Remarks/RemarksTests: lib/libLLVMBitstreamReader.a
unittests/Remarks/RemarksTests: lib/libLLVMBinaryFormat.a
unittests/Remarks/RemarksTests: lib/libLLVMSupport.a
unittests/Remarks/RemarksTests: lib/libLLVMDemangle.a
unittests/Remarks/RemarksTests: unittests/Remarks/CMakeFiles/RemarksTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable RemarksTests"
	cd /home/namrata/libc++-build-10/unittests/Remarks && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RemarksTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unittests/Remarks/CMakeFiles/RemarksTests.dir/build: unittests/Remarks/RemarksTests

.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/build

unittests/Remarks/CMakeFiles/RemarksTests.dir/requires: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksFormatTest.cpp.o.requires
unittests/Remarks/CMakeFiles/RemarksTests.dir/requires: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksParsingTest.cpp.o.requires
unittests/Remarks/CMakeFiles/RemarksTests.dir/requires: unittests/Remarks/CMakeFiles/RemarksTests.dir/BitstreamRemarksSerializerTest.cpp.o.requires
unittests/Remarks/CMakeFiles/RemarksTests.dir/requires: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksAPITest.cpp.o.requires
unittests/Remarks/CMakeFiles/RemarksTests.dir/requires: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksLinkingTest.cpp.o.requires
unittests/Remarks/CMakeFiles/RemarksTests.dir/requires: unittests/Remarks/CMakeFiles/RemarksTests.dir/RemarksStrTabParsingTest.cpp.o.requires
unittests/Remarks/CMakeFiles/RemarksTests.dir/requires: unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksParsingTest.cpp.o.requires
unittests/Remarks/CMakeFiles/RemarksTests.dir/requires: unittests/Remarks/CMakeFiles/RemarksTests.dir/YAMLRemarksSerializerTest.cpp.o.requires

.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/requires

unittests/Remarks/CMakeFiles/RemarksTests.dir/clean:
	cd /home/namrata/libc++-build-10/unittests/Remarks && $(CMAKE_COMMAND) -P CMakeFiles/RemarksTests.dir/cmake_clean.cmake
.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/clean

unittests/Remarks/CMakeFiles/RemarksTests.dir/depend:
	cd /home/namrata/libc++-build-10 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/namrata/libc++-10/llvm /home/namrata/libc++-10/llvm/unittests/Remarks /home/namrata/libc++-build-10 /home/namrata/libc++-build-10/unittests/Remarks /home/namrata/libc++-build-10/unittests/Remarks/CMakeFiles/RemarksTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unittests/Remarks/CMakeFiles/RemarksTests.dir/depend
