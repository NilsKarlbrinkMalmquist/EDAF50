# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = "/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14/build2"

# Include any dependencies generated for this target.
include CMakeFiles/ltest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ltest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ltest.dir/flags.make

CMakeFiles/ltest.dir/ltest.cc.o: CMakeFiles/ltest.dir/flags.make
CMakeFiles/ltest.dir/ltest.cc.o: ../ltest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14/build2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ltest.dir/ltest.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ltest.dir/ltest.cc.o -c "/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14/ltest.cc"

CMakeFiles/ltest.dir/ltest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ltest.dir/ltest.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14/ltest.cc" > CMakeFiles/ltest.dir/ltest.cc.i

CMakeFiles/ltest.dir/ltest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ltest.dir/ltest.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14/ltest.cc" -o CMakeFiles/ltest.dir/ltest.cc.s

# Object files for target ltest
ltest_OBJECTS = \
"CMakeFiles/ltest.dir/ltest.cc.o"

# External object files for target ltest
ltest_EXTERNAL_OBJECTS =

ltest: CMakeFiles/ltest.dir/ltest.cc.o
ltest: CMakeFiles/ltest.dir/build.make
ltest: liblab1/libTestLib.a
ltest: CMakeFiles/ltest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14/build2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ltest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ltest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ltest.dir/build: ltest

.PHONY : CMakeFiles/ltest.dir/build

CMakeFiles/ltest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ltest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ltest.dir/clean

CMakeFiles/ltest.dir/depend:
	cd "/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14/build2" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14" "/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14" "/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14/build2" "/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14/build2" "/mnt/c/Users/morri/Google Drive/LTH År 5/C++ Programmering/EDAF50/Labs/lab1/A14/build2/CMakeFiles/ltest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ltest.dir/depend
