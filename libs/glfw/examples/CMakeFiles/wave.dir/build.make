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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.13.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.13.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/julyzamora/Desktop/Game/game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/julyzamora/Desktop/Game/game

# Include any dependencies generated for this target.
include libs/glfw/examples/CMakeFiles/wave.dir/depend.make

# Include the progress variables for this target.
include libs/glfw/examples/CMakeFiles/wave.dir/progress.make

# Include the compile flags for this target's objects.
include libs/glfw/examples/CMakeFiles/wave.dir/flags.make

libs/glfw/examples/wave.app/Contents/Resources/glfw.icns: libs/glfw/examples/glfw.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content libs/glfw/examples/wave.app/Contents/Resources/glfw.icns"
	$(CMAKE_COMMAND) -E copy /Users/julyzamora/Desktop/Game/game/libs/glfw/examples/glfw.icns libs/glfw/examples/wave.app/Contents/Resources/glfw.icns

libs/glfw/examples/CMakeFiles/wave.dir/wave.c.o: libs/glfw/examples/CMakeFiles/wave.dir/flags.make
libs/glfw/examples/CMakeFiles/wave.dir/wave.c.o: libs/glfw/examples/wave.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/glfw/examples/CMakeFiles/wave.dir/wave.c.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wave.dir/wave.c.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/examples/wave.c

libs/glfw/examples/CMakeFiles/wave.dir/wave.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wave.dir/wave.c.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/examples/wave.c > CMakeFiles/wave.dir/wave.c.i

libs/glfw/examples/CMakeFiles/wave.dir/wave.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wave.dir/wave.c.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/examples/wave.c -o CMakeFiles/wave.dir/wave.c.s

libs/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o: libs/glfw/examples/CMakeFiles/wave.dir/flags.make
libs/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o: libs/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libs/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wave.dir/__/deps/glad.c.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/deps/glad.c

libs/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wave.dir/__/deps/glad.c.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/deps/glad.c > CMakeFiles/wave.dir/__/deps/glad.c.i

libs/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wave.dir/__/deps/glad.c.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/deps/glad.c -o CMakeFiles/wave.dir/__/deps/glad.c.s

# Object files for target wave
wave_OBJECTS = \
"CMakeFiles/wave.dir/wave.c.o" \
"CMakeFiles/wave.dir/__/deps/glad.c.o"

# External object files for target wave
wave_EXTERNAL_OBJECTS =

libs/glfw/examples/wave.app/Contents/MacOS/wave: libs/glfw/examples/CMakeFiles/wave.dir/wave.c.o
libs/glfw/examples/wave.app/Contents/MacOS/wave: libs/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o
libs/glfw/examples/wave.app/Contents/MacOS/wave: libs/glfw/examples/CMakeFiles/wave.dir/build.make
libs/glfw/examples/wave.app/Contents/MacOS/wave: libs/glfw/src/libglfw3.a
libs/glfw/examples/wave.app/Contents/MacOS/wave: libs/glfw/examples/CMakeFiles/wave.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable wave.app/Contents/MacOS/wave"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wave.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/glfw/examples/CMakeFiles/wave.dir/build: libs/glfw/examples/wave.app/Contents/MacOS/wave
libs/glfw/examples/CMakeFiles/wave.dir/build: libs/glfw/examples/wave.app/Contents/Resources/glfw.icns

.PHONY : libs/glfw/examples/CMakeFiles/wave.dir/build

libs/glfw/examples/CMakeFiles/wave.dir/clean:
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/examples && $(CMAKE_COMMAND) -P CMakeFiles/wave.dir/cmake_clean.cmake
.PHONY : libs/glfw/examples/CMakeFiles/wave.dir/clean

libs/glfw/examples/CMakeFiles/wave.dir/depend:
	cd /Users/julyzamora/Desktop/Game/game && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/julyzamora/Desktop/Game/game /Users/julyzamora/Desktop/Game/game/libs/glfw/examples /Users/julyzamora/Desktop/Game/game /Users/julyzamora/Desktop/Game/game/libs/glfw/examples /Users/julyzamora/Desktop/Game/game/libs/glfw/examples/CMakeFiles/wave.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/glfw/examples/CMakeFiles/wave.dir/depend

