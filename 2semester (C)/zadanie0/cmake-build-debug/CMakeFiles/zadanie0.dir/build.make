# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/zadanie0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zadanie0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zadanie0.dir/flags.make

CMakeFiles/zadanie0.dir/main.c.obj: CMakeFiles/zadanie0.dir/flags.make
CMakeFiles/zadanie0.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/zadanie0.dir/main.c.obj"
	E:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\zadanie0.dir\main.c.obj   -c "D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0\main.c"

CMakeFiles/zadanie0.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zadanie0.dir/main.c.i"
	E:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0\main.c" > CMakeFiles\zadanie0.dir\main.c.i

CMakeFiles/zadanie0.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zadanie0.dir/main.c.s"
	E:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0\main.c" -o CMakeFiles\zadanie0.dir\main.c.s

# Object files for target zadanie0
zadanie0_OBJECTS = \
"CMakeFiles/zadanie0.dir/main.c.obj"

# External object files for target zadanie0
zadanie0_EXTERNAL_OBJECTS =

zadanie0.exe: CMakeFiles/zadanie0.dir/main.c.obj
zadanie0.exe: CMakeFiles/zadanie0.dir/build.make
zadanie0.exe: CMakeFiles/zadanie0.dir/linklibs.rsp
zadanie0.exe: CMakeFiles/zadanie0.dir/objects1.rsp
zadanie0.exe: CMakeFiles/zadanie0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable zadanie0.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zadanie0.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zadanie0.dir/build: zadanie0.exe

.PHONY : CMakeFiles/zadanie0.dir/build

CMakeFiles/zadanie0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zadanie0.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zadanie0.dir/clean

CMakeFiles/zadanie0.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0" "D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0" "D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0\cmake-build-debug" "D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0\cmake-build-debug" "D:\Skola\vysoka skola\1.rocnik\Programovanie\2semester C\zadanie0\cmake-build-debug\CMakeFiles\zadanie0.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/zadanie0.dir/depend

