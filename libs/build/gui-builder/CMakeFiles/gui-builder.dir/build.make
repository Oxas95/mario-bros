# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = "/home/user/Bureau/mario bros/libs/TGUI"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/user/Bureau/mario bros/libs/build"

# Include any dependencies generated for this target.
include gui-builder/CMakeFiles/gui-builder.dir/depend.make

# Include the progress variables for this target.
include gui-builder/CMakeFiles/gui-builder.dir/progress.make

# Include the compile flags for this target's objects.
include gui-builder/CMakeFiles/gui-builder.dir/flags.make

gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o: gui-builder/CMakeFiles/gui-builder.dir/flags.make
gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o: /home/user/Bureau/mario\ bros/libs/TGUI/gui-builder/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/user/Bureau/mario bros/libs/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o"
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui-builder.dir/src/main.cpp.o -c "/home/user/Bureau/mario bros/libs/TGUI/gui-builder/src/main.cpp"

gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui-builder.dir/src/main.cpp.i"
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/user/Bureau/mario bros/libs/TGUI/gui-builder/src/main.cpp" > CMakeFiles/gui-builder.dir/src/main.cpp.i

gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui-builder.dir/src/main.cpp.s"
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/user/Bureau/mario bros/libs/TGUI/gui-builder/src/main.cpp" -o CMakeFiles/gui-builder.dir/src/main.cpp.s

gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o.requires:

.PHONY : gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o.requires

gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o.provides: gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o.requires
	$(MAKE) -f gui-builder/CMakeFiles/gui-builder.dir/build.make gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o.provides.build
.PHONY : gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o.provides

gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o.provides.build: gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o


gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o: gui-builder/CMakeFiles/gui-builder.dir/flags.make
gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o: /home/user/Bureau/mario\ bros/libs/TGUI/gui-builder/src/Form.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/user/Bureau/mario bros/libs/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o"
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui-builder.dir/src/Form.cpp.o -c "/home/user/Bureau/mario bros/libs/TGUI/gui-builder/src/Form.cpp"

gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui-builder.dir/src/Form.cpp.i"
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/user/Bureau/mario bros/libs/TGUI/gui-builder/src/Form.cpp" > CMakeFiles/gui-builder.dir/src/Form.cpp.i

gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui-builder.dir/src/Form.cpp.s"
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/user/Bureau/mario bros/libs/TGUI/gui-builder/src/Form.cpp" -o CMakeFiles/gui-builder.dir/src/Form.cpp.s

gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o.requires:

.PHONY : gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o.requires

gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o.provides: gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o.requires
	$(MAKE) -f gui-builder/CMakeFiles/gui-builder.dir/build.make gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o.provides.build
.PHONY : gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o.provides

gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o.provides.build: gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o


gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o: gui-builder/CMakeFiles/gui-builder.dir/flags.make
gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o: /home/user/Bureau/mario\ bros/libs/TGUI/gui-builder/src/GuiBuilder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/user/Bureau/mario bros/libs/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o"
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o -c "/home/user/Bureau/mario bros/libs/TGUI/gui-builder/src/GuiBuilder.cpp"

gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.i"
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/user/Bureau/mario bros/libs/TGUI/gui-builder/src/GuiBuilder.cpp" > CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.i

gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.s"
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/user/Bureau/mario bros/libs/TGUI/gui-builder/src/GuiBuilder.cpp" -o CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.s

gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o.requires:

.PHONY : gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o.requires

gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o.provides: gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o.requires
	$(MAKE) -f gui-builder/CMakeFiles/gui-builder.dir/build.make gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o.provides.build
.PHONY : gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o.provides

gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o.provides.build: gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o


# Object files for target gui-builder
gui__builder_OBJECTS = \
"CMakeFiles/gui-builder.dir/src/main.cpp.o" \
"CMakeFiles/gui-builder.dir/src/Form.cpp.o" \
"CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o"

# External object files for target gui-builder
gui__builder_EXTERNAL_OBJECTS =

gui-builder/gui-builder: gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o
gui-builder/gui-builder: gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o
gui-builder/gui-builder: gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o
gui-builder/gui-builder: gui-builder/CMakeFiles/gui-builder.dir/build.make
gui-builder/gui-builder: lib/libtgui.so.0.8.5
gui-builder/gui-builder: /usr/local/lib/libsfml-graphics.so
gui-builder/gui-builder: /usr/local/lib/libsfml-window.so
gui-builder/gui-builder: /usr/local/lib/libsfml-system.so
gui-builder/gui-builder: gui-builder/CMakeFiles/gui-builder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/user/Bureau/mario bros/libs/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable gui-builder"
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gui-builder.dir/link.txt --verbose=$(VERBOSE)
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && /usr/bin/cmake -E copy /home/user/Bureau/mario\ bros/libs/build/gui-builder/gui-builder /home/user/Bureau/mario\ bros/libs/TGUI/gui-builder/
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && /usr/bin/cmake -E copy_directory /home/user/Bureau/mario\ bros/libs/TGUI/themes /home/user/Bureau/mario\ bros/libs/TGUI/gui-builder/themes

# Rule to build all files generated by this target.
gui-builder/CMakeFiles/gui-builder.dir/build: gui-builder/gui-builder

.PHONY : gui-builder/CMakeFiles/gui-builder.dir/build

gui-builder/CMakeFiles/gui-builder.dir/requires: gui-builder/CMakeFiles/gui-builder.dir/src/main.cpp.o.requires
gui-builder/CMakeFiles/gui-builder.dir/requires: gui-builder/CMakeFiles/gui-builder.dir/src/Form.cpp.o.requires
gui-builder/CMakeFiles/gui-builder.dir/requires: gui-builder/CMakeFiles/gui-builder.dir/src/GuiBuilder.cpp.o.requires

.PHONY : gui-builder/CMakeFiles/gui-builder.dir/requires

gui-builder/CMakeFiles/gui-builder.dir/clean:
	cd "/home/user/Bureau/mario bros/libs/build/gui-builder" && $(CMAKE_COMMAND) -P CMakeFiles/gui-builder.dir/cmake_clean.cmake
.PHONY : gui-builder/CMakeFiles/gui-builder.dir/clean

gui-builder/CMakeFiles/gui-builder.dir/depend:
	cd "/home/user/Bureau/mario bros/libs/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/user/Bureau/mario bros/libs/TGUI" "/home/user/Bureau/mario bros/libs/TGUI/gui-builder" "/home/user/Bureau/mario bros/libs/build" "/home/user/Bureau/mario bros/libs/build/gui-builder" "/home/user/Bureau/mario bros/libs/build/gui-builder/CMakeFiles/gui-builder.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : gui-builder/CMakeFiles/gui-builder.dir/depend

