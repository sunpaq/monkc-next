# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sunyuli/Dev/monkc3/monkc3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sunyuli/Dev/monkc3/monkc3

# Include any dependencies generated for this target.
include app/CMakeFiles/demo.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/demo.dir/flags.make

app/CMakeFiles/demo.dir/Cell.c.o: app/CMakeFiles/demo.dir/flags.make
app/CMakeFiles/demo.dir/Cell.c.o: app/Cell.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunyuli/Dev/monkc3/monkc3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object app/CMakeFiles/demo.dir/Cell.c.o"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/demo.dir/Cell.c.o   -c /Users/sunyuli/Dev/monkc3/monkc3/app/Cell.c

app/CMakeFiles/demo.dir/Cell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo.dir/Cell.c.i"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sunyuli/Dev/monkc3/monkc3/app/Cell.c > CMakeFiles/demo.dir/Cell.c.i

app/CMakeFiles/demo.dir/Cell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo.dir/Cell.c.s"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sunyuli/Dev/monkc3/monkc3/app/Cell.c -o CMakeFiles/demo.dir/Cell.c.s

app/CMakeFiles/demo.dir/Fish.c.o: app/CMakeFiles/demo.dir/flags.make
app/CMakeFiles/demo.dir/Fish.c.o: app/Fish.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunyuli/Dev/monkc3/monkc3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object app/CMakeFiles/demo.dir/Fish.c.o"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/demo.dir/Fish.c.o   -c /Users/sunyuli/Dev/monkc3/monkc3/app/Fish.c

app/CMakeFiles/demo.dir/Fish.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo.dir/Fish.c.i"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sunyuli/Dev/monkc3/monkc3/app/Fish.c > CMakeFiles/demo.dir/Fish.c.i

app/CMakeFiles/demo.dir/Fish.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo.dir/Fish.c.s"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sunyuli/Dev/monkc3/monkc3/app/Fish.c -o CMakeFiles/demo.dir/Fish.c.s

app/CMakeFiles/demo.dir/SimpleServer.c.o: app/CMakeFiles/demo.dir/flags.make
app/CMakeFiles/demo.dir/SimpleServer.c.o: app/SimpleServer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunyuli/Dev/monkc3/monkc3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object app/CMakeFiles/demo.dir/SimpleServer.c.o"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/demo.dir/SimpleServer.c.o   -c /Users/sunyuli/Dev/monkc3/monkc3/app/SimpleServer.c

app/CMakeFiles/demo.dir/SimpleServer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo.dir/SimpleServer.c.i"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sunyuli/Dev/monkc3/monkc3/app/SimpleServer.c > CMakeFiles/demo.dir/SimpleServer.c.i

app/CMakeFiles/demo.dir/SimpleServer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo.dir/SimpleServer.c.s"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sunyuli/Dev/monkc3/monkc3/app/SimpleServer.c -o CMakeFiles/demo.dir/SimpleServer.c.s

app/CMakeFiles/demo.dir/main.c.o: app/CMakeFiles/demo.dir/flags.make
app/CMakeFiles/demo.dir/main.c.o: app/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunyuli/Dev/monkc3/monkc3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object app/CMakeFiles/demo.dir/main.c.o"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/demo.dir/main.c.o   -c /Users/sunyuli/Dev/monkc3/monkc3/app/main.c

app/CMakeFiles/demo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo.dir/main.c.i"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sunyuli/Dev/monkc3/monkc3/app/main.c > CMakeFiles/demo.dir/main.c.i

app/CMakeFiles/demo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo.dir/main.c.s"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sunyuli/Dev/monkc3/monkc3/app/main.c -o CMakeFiles/demo.dir/main.c.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/Cell.c.o" \
"CMakeFiles/demo.dir/Fish.c.o" \
"CMakeFiles/demo.dir/SimpleServer.c.o" \
"CMakeFiles/demo.dir/main.c.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

app/demo: app/CMakeFiles/demo.dir/Cell.c.o
app/demo: app/CMakeFiles/demo.dir/Fish.c.o
app/demo: app/CMakeFiles/demo.dir/SimpleServer.c.o
app/demo: app/CMakeFiles/demo.dir/main.c.o
app/demo: app/CMakeFiles/demo.dir/build.make
app/demo: runtime/libmonkc-runtime.a
app/demo: app/CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sunyuli/Dev/monkc3/monkc3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable demo"
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/demo.dir/build: app/demo

.PHONY : app/CMakeFiles/demo.dir/build

app/CMakeFiles/demo.dir/clean:
	cd /Users/sunyuli/Dev/monkc3/monkc3/app && $(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/demo.dir/clean

app/CMakeFiles/demo.dir/depend:
	cd /Users/sunyuli/Dev/monkc3/monkc3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sunyuli/Dev/monkc3/monkc3 /Users/sunyuli/Dev/monkc3/monkc3/app /Users/sunyuli/Dev/monkc3/monkc3 /Users/sunyuli/Dev/monkc3/monkc3/app /Users/sunyuli/Dev/monkc3/monkc3/app/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/demo.dir/depend

