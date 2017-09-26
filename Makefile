# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /opt/harlan/CompSocChat/gaffertape

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/harlan/CompSocChat/gaffertape

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /opt/harlan/CompSocChat/gaffertape/CMakeFiles /opt/harlan/CompSocChat/gaffertape/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /opt/harlan/CompSocChat/gaffertape/CMakeFiles 0
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
# Target rules for targets named gaffertape-webserver

# Build rule for target.
gaffertape-webserver: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gaffertape-webserver
.PHONY : gaffertape-webserver

# fast build rule for target.
gaffertape-webserver/fast:
	$(MAKE) -f CMakeFiles/gaffertape-webserver.dir/build.make CMakeFiles/gaffertape-webserver.dir/build
.PHONY : gaffertape-webserver/fast

#=============================================================================
# Target rules for targets named gaffertape

# Build rule for target.
gaffertape: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gaffertape
.PHONY : gaffertape

# fast build rule for target.
gaffertape/fast:
	$(MAKE) -f CMakeFiles/gaffertape.dir/build.make CMakeFiles/gaffertape.dir/build
.PHONY : gaffertape/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/gaffertape.dir/build.make CMakeFiles/gaffertape.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/gaffertape.dir/build.make CMakeFiles/gaffertape.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/gaffertape.dir/build.make CMakeFiles/gaffertape.dir/main.cpp.s
.PHONY : main.cpp.s

webserver/get.o: webserver/get.cpp.o

.PHONY : webserver/get.o

# target to build an object file
webserver/get.cpp.o:
	$(MAKE) -f CMakeFiles/gaffertape-webserver.dir/build.make CMakeFiles/gaffertape-webserver.dir/webserver/get.cpp.o
.PHONY : webserver/get.cpp.o

webserver/get.i: webserver/get.cpp.i

.PHONY : webserver/get.i

# target to preprocess a source file
webserver/get.cpp.i:
	$(MAKE) -f CMakeFiles/gaffertape-webserver.dir/build.make CMakeFiles/gaffertape-webserver.dir/webserver/get.cpp.i
.PHONY : webserver/get.cpp.i

webserver/get.s: webserver/get.cpp.s

.PHONY : webserver/get.s

# target to generate assembly for a file
webserver/get.cpp.s:
	$(MAKE) -f CMakeFiles/gaffertape-webserver.dir/build.make CMakeFiles/gaffertape-webserver.dir/webserver/get.cpp.s
.PHONY : webserver/get.cpp.s

webserver/post.o: webserver/post.cpp.o

.PHONY : webserver/post.o

# target to build an object file
webserver/post.cpp.o:
	$(MAKE) -f CMakeFiles/gaffertape-webserver.dir/build.make CMakeFiles/gaffertape-webserver.dir/webserver/post.cpp.o
.PHONY : webserver/post.cpp.o

webserver/post.i: webserver/post.cpp.i

.PHONY : webserver/post.i

# target to preprocess a source file
webserver/post.cpp.i:
	$(MAKE) -f CMakeFiles/gaffertape-webserver.dir/build.make CMakeFiles/gaffertape-webserver.dir/webserver/post.cpp.i
.PHONY : webserver/post.cpp.i

webserver/post.s: webserver/post.cpp.s

.PHONY : webserver/post.s

# target to generate assembly for a file
webserver/post.cpp.s:
	$(MAKE) -f CMakeFiles/gaffertape-webserver.dir/build.make CMakeFiles/gaffertape-webserver.dir/webserver/post.cpp.s
.PHONY : webserver/post.cpp.s

webserver/server.o: webserver/server.cpp.o

.PHONY : webserver/server.o

# target to build an object file
webserver/server.cpp.o:
	$(MAKE) -f CMakeFiles/gaffertape-webserver.dir/build.make CMakeFiles/gaffertape-webserver.dir/webserver/server.cpp.o
.PHONY : webserver/server.cpp.o

webserver/server.i: webserver/server.cpp.i

.PHONY : webserver/server.i

# target to preprocess a source file
webserver/server.cpp.i:
	$(MAKE) -f CMakeFiles/gaffertape-webserver.dir/build.make CMakeFiles/gaffertape-webserver.dir/webserver/server.cpp.i
.PHONY : webserver/server.cpp.i

webserver/server.s: webserver/server.cpp.s

.PHONY : webserver/server.s

# target to generate assembly for a file
webserver/server.cpp.s:
	$(MAKE) -f CMakeFiles/gaffertape-webserver.dir/build.make CMakeFiles/gaffertape-webserver.dir/webserver/server.cpp.s
.PHONY : webserver/server.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... gaffertape-webserver"
	@echo "... gaffertape"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... webserver/get.o"
	@echo "... webserver/get.i"
	@echo "... webserver/get.s"
	@echo "... webserver/post.o"
	@echo "... webserver/post.i"
	@echo "... webserver/post.s"
	@echo "... webserver/server.o"
	@echo "... webserver/server.i"
	@echo "... webserver/server.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

