# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nishimura/Developments/Cplusplus/Sync/03_ToStudyOthers/EC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nishimura/Developments/Cplusplus/Sync/03_ToStudyOthers/EC

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/nishimura/Developments/Cplusplus/Sync/03_ToStudyOthers/EC/CMakeFiles /home/nishimura/Developments/Cplusplus/Sync/03_ToStudyOthers/EC/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/nishimura/Developments/Cplusplus/Sync/03_ToStudyOthers/EC/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

GA.o: GA.cpp.o
.PHONY : GA.o

# target to build an object file
GA.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/GA.cpp.o
.PHONY : GA.cpp.o

GA.i: GA.cpp.i
.PHONY : GA.i

# target to preprocess a source file
GA.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/GA.cpp.i
.PHONY : GA.cpp.i

GA.s: GA.cpp.s
.PHONY : GA.s

# target to generate assembly for a file
GA.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/GA.cpp.s
.PHONY : GA.cpp.s

GeneticOperator.o: GeneticOperator.cpp.o
.PHONY : GeneticOperator.o

# target to build an object file
GeneticOperator.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/GeneticOperator.cpp.o
.PHONY : GeneticOperator.cpp.o

GeneticOperator.i: GeneticOperator.cpp.i
.PHONY : GeneticOperator.i

# target to preprocess a source file
GeneticOperator.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/GeneticOperator.cpp.i
.PHONY : GeneticOperator.cpp.i

GeneticOperator.s: GeneticOperator.cpp.s
.PHONY : GeneticOperator.s

# target to generate assembly for a file
GeneticOperator.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/GeneticOperator.cpp.s
.PHONY : GeneticOperator.cpp.s

individual.o: individual.cpp.o
.PHONY : individual.o

# target to build an object file
individual.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/individual.cpp.o
.PHONY : individual.cpp.o

individual.i: individual.cpp.i
.PHONY : individual.i

# target to preprocess a source file
individual.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/individual.cpp.i
.PHONY : individual.cpp.i

individual.s: individual.cpp.s
.PHONY : individual.s

# target to generate assembly for a file
individual.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/individual.cpp.s
.PHONY : individual.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... main"
	@echo "... rebuild_cache"
	@echo "... GA.o"
	@echo "... GA.i"
	@echo "... GA.s"
	@echo "... GeneticOperator.o"
	@echo "... GeneticOperator.i"
	@echo "... GeneticOperator.s"
	@echo "... individual.o"
	@echo "... individual.i"
	@echo "... individual.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

