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
include libs/glfw/src/CMakeFiles/glfw.dir/depend.make

# Include the progress variables for this target.
include libs/glfw/src/CMakeFiles/glfw.dir/progress.make

# Include the compile flags for this target's objects.
include libs/glfw/src/CMakeFiles/glfw.dir/flags.make

libs/glfw/src/CMakeFiles/glfw.dir/context.c.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/context.c.o: libs/glfw/src/context.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/context.c.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/context.c.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/context.c

libs/glfw/src/CMakeFiles/glfw.dir/context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/context.c.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/context.c > CMakeFiles/glfw.dir/context.c.i

libs/glfw/src/CMakeFiles/glfw.dir/context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/context.c.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/context.c -o CMakeFiles/glfw.dir/context.c.s

libs/glfw/src/CMakeFiles/glfw.dir/init.c.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/init.c.o: libs/glfw/src/init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/init.c.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/init.c.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/init.c

libs/glfw/src/CMakeFiles/glfw.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/init.c.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/init.c > CMakeFiles/glfw.dir/init.c.i

libs/glfw/src/CMakeFiles/glfw.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/init.c.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/init.c -o CMakeFiles/glfw.dir/init.c.s

libs/glfw/src/CMakeFiles/glfw.dir/input.c.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/input.c.o: libs/glfw/src/input.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/input.c.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/input.c.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/input.c

libs/glfw/src/CMakeFiles/glfw.dir/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/input.c.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/input.c > CMakeFiles/glfw.dir/input.c.i

libs/glfw/src/CMakeFiles/glfw.dir/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/input.c.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/input.c -o CMakeFiles/glfw.dir/input.c.s

libs/glfw/src/CMakeFiles/glfw.dir/monitor.c.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/monitor.c.o: libs/glfw/src/monitor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/monitor.c.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/monitor.c.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/monitor.c

libs/glfw/src/CMakeFiles/glfw.dir/monitor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/monitor.c.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/monitor.c > CMakeFiles/glfw.dir/monitor.c.i

libs/glfw/src/CMakeFiles/glfw.dir/monitor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/monitor.c.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/monitor.c -o CMakeFiles/glfw.dir/monitor.c.s

libs/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o: libs/glfw/src/vulkan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/vulkan.c.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/vulkan.c

libs/glfw/src/CMakeFiles/glfw.dir/vulkan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/vulkan.c.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/vulkan.c > CMakeFiles/glfw.dir/vulkan.c.i

libs/glfw/src/CMakeFiles/glfw.dir/vulkan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/vulkan.c.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/vulkan.c -o CMakeFiles/glfw.dir/vulkan.c.s

libs/glfw/src/CMakeFiles/glfw.dir/window.c.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/window.c.o: libs/glfw/src/window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/window.c.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/window.c.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/window.c

libs/glfw/src/CMakeFiles/glfw.dir/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/window.c.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/window.c > CMakeFiles/glfw.dir/window.c.i

libs/glfw/src/CMakeFiles/glfw.dir/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/window.c.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/window.c -o CMakeFiles/glfw.dir/window.c.s

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.o: libs/glfw/src/cocoa_init.m
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/cocoa_init.m.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_init.m

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/cocoa_init.m.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_init.m > CMakeFiles/glfw.dir/cocoa_init.m.i

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/cocoa_init.m.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_init.m -o CMakeFiles/glfw.dir/cocoa_init.m.s

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_joystick.m.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/cocoa_joystick.m.o: libs/glfw/src/cocoa_joystick.m
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/cocoa_joystick.m.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/cocoa_joystick.m.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_joystick.m

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_joystick.m.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/cocoa_joystick.m.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_joystick.m > CMakeFiles/glfw.dir/cocoa_joystick.m.i

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_joystick.m.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/cocoa_joystick.m.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_joystick.m -o CMakeFiles/glfw.dir/cocoa_joystick.m.s

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.o: libs/glfw/src/cocoa_monitor.m
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/cocoa_monitor.m.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_monitor.m

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/cocoa_monitor.m.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_monitor.m > CMakeFiles/glfw.dir/cocoa_monitor.m.i

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/cocoa_monitor.m.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_monitor.m -o CMakeFiles/glfw.dir/cocoa_monitor.m.s

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.o: libs/glfw/src/cocoa_window.m
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/cocoa_window.m.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_window.m

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/cocoa_window.m.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_window.m > CMakeFiles/glfw.dir/cocoa_window.m.i

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/cocoa_window.m.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_window.m -o CMakeFiles/glfw.dir/cocoa_window.m.s

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_time.c.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/cocoa_time.c.o: libs/glfw/src/cocoa_time.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/cocoa_time.c.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/cocoa_time.c.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_time.c

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/cocoa_time.c.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_time.c > CMakeFiles/glfw.dir/cocoa_time.c.i

libs/glfw/src/CMakeFiles/glfw.dir/cocoa_time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/cocoa_time.c.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/cocoa_time.c -o CMakeFiles/glfw.dir/cocoa_time.c.s

libs/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o: libs/glfw/src/posix_tls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/posix_tls.c.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/posix_tls.c

libs/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/posix_tls.c.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/posix_tls.c > CMakeFiles/glfw.dir/posix_tls.c.i

libs/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/posix_tls.c.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/posix_tls.c -o CMakeFiles/glfw.dir/posix_tls.c.s

libs/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.o: libs/glfw/src/CMakeFiles/glfw.dir/flags.make
libs/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.o: libs/glfw/src/nsgl_context.m
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object libs/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.o"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/nsgl_context.m.o   -c /Users/julyzamora/Desktop/Game/game/libs/glfw/src/nsgl_context.m

libs/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/nsgl_context.m.i"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/julyzamora/Desktop/Game/game/libs/glfw/src/nsgl_context.m > CMakeFiles/glfw.dir/nsgl_context.m.i

libs/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/nsgl_context.m.s"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/julyzamora/Desktop/Game/game/libs/glfw/src/nsgl_context.m -o CMakeFiles/glfw.dir/nsgl_context.m.s

# Object files for target glfw
glfw_OBJECTS = \
"CMakeFiles/glfw.dir/context.c.o" \
"CMakeFiles/glfw.dir/init.c.o" \
"CMakeFiles/glfw.dir/input.c.o" \
"CMakeFiles/glfw.dir/monitor.c.o" \
"CMakeFiles/glfw.dir/vulkan.c.o" \
"CMakeFiles/glfw.dir/window.c.o" \
"CMakeFiles/glfw.dir/cocoa_init.m.o" \
"CMakeFiles/glfw.dir/cocoa_joystick.m.o" \
"CMakeFiles/glfw.dir/cocoa_monitor.m.o" \
"CMakeFiles/glfw.dir/cocoa_window.m.o" \
"CMakeFiles/glfw.dir/cocoa_time.c.o" \
"CMakeFiles/glfw.dir/posix_tls.c.o" \
"CMakeFiles/glfw.dir/nsgl_context.m.o"

# External object files for target glfw
glfw_EXTERNAL_OBJECTS =

libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/context.c.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/init.c.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/input.c.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/monitor.c.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/window.c.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/cocoa_joystick.m.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/cocoa_time.c.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.o
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/build.make
libs/glfw/src/libglfw3.a: libs/glfw/src/CMakeFiles/glfw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/julyzamora/Desktop/Game/game/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C static library libglfw3.a"
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/glfw.dir/cmake_clean_target.cmake
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/glfw/src/CMakeFiles/glfw.dir/build: libs/glfw/src/libglfw3.a

.PHONY : libs/glfw/src/CMakeFiles/glfw.dir/build

libs/glfw/src/CMakeFiles/glfw.dir/clean:
	cd /Users/julyzamora/Desktop/Game/game/libs/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/glfw.dir/cmake_clean.cmake
.PHONY : libs/glfw/src/CMakeFiles/glfw.dir/clean

libs/glfw/src/CMakeFiles/glfw.dir/depend:
	cd /Users/julyzamora/Desktop/Game/game && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/julyzamora/Desktop/Game/game /Users/julyzamora/Desktop/Game/game/libs/glfw/src /Users/julyzamora/Desktop/Game/game /Users/julyzamora/Desktop/Game/game/libs/glfw/src /Users/julyzamora/Desktop/Game/game/libs/glfw/src/CMakeFiles/glfw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/glfw/src/CMakeFiles/glfw.dir/depend

