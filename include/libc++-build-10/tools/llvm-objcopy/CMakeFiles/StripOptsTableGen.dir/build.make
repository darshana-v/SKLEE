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

# Utility rule file for StripOptsTableGen.

# Include the progress variables for this target.
include tools/llvm-objcopy/CMakeFiles/StripOptsTableGen.dir/progress.make

tools/llvm-objcopy/CMakeFiles/StripOptsTableGen: tools/llvm-objcopy/ObjcopyOpts.inc
tools/llvm-objcopy/CMakeFiles/StripOptsTableGen: tools/llvm-objcopy/InstallNameToolOpts.inc
tools/llvm-objcopy/CMakeFiles/StripOptsTableGen: tools/llvm-objcopy/StripOpts.inc


tools/llvm-objcopy/ObjcopyOpts.inc: bin/llvm-tblgen
tools/llvm-objcopy/ObjcopyOpts.inc: bin/llvm-tblgen
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/CommonOpts.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/InstallNameToolOpts.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/ObjcopyOpts.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/StripOpts.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/CodeGen/SDNodeProperties.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/CodeGen/ValueTypes.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/Attributes.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/Intrinsics.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsAArch64.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsAMDGPU.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsARM.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsBPF.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsHexagon.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsMips.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsNVVM.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsPowerPC.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsRISCV.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsSystemZ.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsWebAssembly.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsX86.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsXCore.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Option/OptParser.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/TableGen/Automaton.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/TableGen/SearchableTable.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GenericOpcodes.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/Combine.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/RegisterBank.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/SelectionDAGCompat.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/Target.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/Target.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetCallingConv.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetInstrPredicate.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetItinerary.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetPfmCounters.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetSchedule.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetSelectionDAG.td
tools/llvm-objcopy/ObjcopyOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/ObjcopyOpts.td
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building ObjcopyOpts.inc..."
	cd /home/namrata/libc++-build-10/tools/llvm-objcopy && ../../bin/llvm-tblgen -gen-opt-parser-defs -I /home/namrata/libc++-10/llvm/tools/llvm-objcopy -I /home/namrata/libc++-10/llvm/include /home/namrata/libc++-10/llvm/tools/llvm-objcopy/ObjcopyOpts.td --write-if-changed -o /home/namrata/libc++-build-10/tools/llvm-objcopy/ObjcopyOpts.inc

tools/llvm-objcopy/InstallNameToolOpts.inc: bin/llvm-tblgen
tools/llvm-objcopy/InstallNameToolOpts.inc: bin/llvm-tblgen
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/CommonOpts.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/InstallNameToolOpts.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/ObjcopyOpts.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/StripOpts.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/CodeGen/SDNodeProperties.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/CodeGen/ValueTypes.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/Attributes.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/Intrinsics.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsAArch64.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsAMDGPU.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsARM.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsBPF.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsHexagon.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsMips.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsNVVM.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsPowerPC.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsRISCV.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsSystemZ.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsWebAssembly.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsX86.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsXCore.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Option/OptParser.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/TableGen/Automaton.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/TableGen/SearchableTable.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GenericOpcodes.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/Combine.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/RegisterBank.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/SelectionDAGCompat.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/Target.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/Target.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetCallingConv.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetInstrPredicate.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetItinerary.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetPfmCounters.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetSchedule.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetSelectionDAG.td
tools/llvm-objcopy/InstallNameToolOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/InstallNameToolOpts.td
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building InstallNameToolOpts.inc..."
	cd /home/namrata/libc++-build-10/tools/llvm-objcopy && ../../bin/llvm-tblgen -gen-opt-parser-defs -I /home/namrata/libc++-10/llvm/tools/llvm-objcopy -I /home/namrata/libc++-10/llvm/include /home/namrata/libc++-10/llvm/tools/llvm-objcopy/InstallNameToolOpts.td --write-if-changed -o /home/namrata/libc++-build-10/tools/llvm-objcopy/InstallNameToolOpts.inc

tools/llvm-objcopy/StripOpts.inc: bin/llvm-tblgen
tools/llvm-objcopy/StripOpts.inc: bin/llvm-tblgen
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/CommonOpts.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/InstallNameToolOpts.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/ObjcopyOpts.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/StripOpts.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/CodeGen/SDNodeProperties.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/CodeGen/ValueTypes.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/Attributes.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/Intrinsics.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsAArch64.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsAMDGPU.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsARM.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsBPF.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsHexagon.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsMips.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsNVVM.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsPowerPC.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsRISCV.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsSystemZ.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsWebAssembly.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsX86.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/IR/IntrinsicsXCore.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Option/OptParser.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/TableGen/Automaton.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/TableGen/SearchableTable.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GenericOpcodes.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/Combine.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/RegisterBank.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/SelectionDAGCompat.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/GlobalISel/Target.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/Target.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetCallingConv.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetInstrPredicate.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetItinerary.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetPfmCounters.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetSchedule.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/include/llvm/Target/TargetSelectionDAG.td
tools/llvm-objcopy/StripOpts.inc: /home/namrata/libc++-10/llvm/tools/llvm-objcopy/StripOpts.td
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/namrata/libc++-build-10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building StripOpts.inc..."
	cd /home/namrata/libc++-build-10/tools/llvm-objcopy && ../../bin/llvm-tblgen -gen-opt-parser-defs -I /home/namrata/libc++-10/llvm/tools/llvm-objcopy -I /home/namrata/libc++-10/llvm/include /home/namrata/libc++-10/llvm/tools/llvm-objcopy/StripOpts.td --write-if-changed -o /home/namrata/libc++-build-10/tools/llvm-objcopy/StripOpts.inc

StripOptsTableGen: tools/llvm-objcopy/CMakeFiles/StripOptsTableGen
StripOptsTableGen: tools/llvm-objcopy/ObjcopyOpts.inc
StripOptsTableGen: tools/llvm-objcopy/InstallNameToolOpts.inc
StripOptsTableGen: tools/llvm-objcopy/StripOpts.inc
StripOptsTableGen: tools/llvm-objcopy/CMakeFiles/StripOptsTableGen.dir/build.make

.PHONY : StripOptsTableGen

# Rule to build all files generated by this target.
tools/llvm-objcopy/CMakeFiles/StripOptsTableGen.dir/build: StripOptsTableGen

.PHONY : tools/llvm-objcopy/CMakeFiles/StripOptsTableGen.dir/build

tools/llvm-objcopy/CMakeFiles/StripOptsTableGen.dir/clean:
	cd /home/namrata/libc++-build-10/tools/llvm-objcopy && $(CMAKE_COMMAND) -P CMakeFiles/StripOptsTableGen.dir/cmake_clean.cmake
.PHONY : tools/llvm-objcopy/CMakeFiles/StripOptsTableGen.dir/clean

tools/llvm-objcopy/CMakeFiles/StripOptsTableGen.dir/depend:
	cd /home/namrata/libc++-build-10 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/namrata/libc++-10/llvm /home/namrata/libc++-10/llvm/tools/llvm-objcopy /home/namrata/libc++-build-10 /home/namrata/libc++-build-10/tools/llvm-objcopy /home/namrata/libc++-build-10/tools/llvm-objcopy/CMakeFiles/StripOptsTableGen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/llvm-objcopy/CMakeFiles/StripOptsTableGen.dir/depend
