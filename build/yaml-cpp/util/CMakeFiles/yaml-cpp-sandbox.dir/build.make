# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jackt\third

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jackt\third\build

# Include any dependencies generated for this target.
include yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/compiler_depend.make

# Include the progress variables for this target.
include yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/progress.make

# Include the compile flags for this target's objects.
include yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/flags.make

yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.obj: yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/flags.make
yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.obj: yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/includes_CXX.rsp
yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.obj: C:/Users/jackt/third/yaml-cpp/util/sandbox.cpp
yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.obj: yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jackt\third\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.obj"
	cd /d C:\Users\jackt\third\build\yaml-cpp\util && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.obj -MF CMakeFiles\yaml-cpp-sandbox.dir\sandbox.cpp.obj.d -o CMakeFiles\yaml-cpp-sandbox.dir\sandbox.cpp.obj -c C:\Users\jackt\third\yaml-cpp\util\sandbox.cpp

yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.i"
	cd /d C:\Users\jackt\third\build\yaml-cpp\util && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jackt\third\yaml-cpp\util\sandbox.cpp > CMakeFiles\yaml-cpp-sandbox.dir\sandbox.cpp.i

yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.s"
	cd /d C:\Users\jackt\third\build\yaml-cpp\util && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jackt\third\yaml-cpp\util\sandbox.cpp -o CMakeFiles\yaml-cpp-sandbox.dir\sandbox.cpp.s

# Object files for target yaml-cpp-sandbox
yaml__cpp__sandbox_OBJECTS = \
"CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.obj"

# External object files for target yaml-cpp-sandbox
yaml__cpp__sandbox_EXTERNAL_OBJECTS =

yaml-cpp/util/sandbox.exe: yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.obj
yaml-cpp/util/sandbox.exe: yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/build.make
yaml-cpp/util/sandbox.exe: yaml-cpp/libyaml-cpp.a
yaml-cpp/util/sandbox.exe: yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/linkLibs.rsp
yaml-cpp/util/sandbox.exe: yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/objects1.rsp
yaml-cpp/util/sandbox.exe: yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jackt\third\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sandbox.exe"
	cd /d C:\Users\jackt\third\build\yaml-cpp\util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\yaml-cpp-sandbox.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/build: yaml-cpp/util/sandbox.exe
.PHONY : yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/build

yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/clean:
	cd /d C:\Users\jackt\third\build\yaml-cpp\util && $(CMAKE_COMMAND) -P CMakeFiles\yaml-cpp-sandbox.dir\cmake_clean.cmake
.PHONY : yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/clean

yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jackt\third C:\Users\jackt\third\yaml-cpp\util C:\Users\jackt\third\build C:\Users\jackt\third\build\yaml-cpp\util C:\Users\jackt\third\build\yaml-cpp\util\CMakeFiles\yaml-cpp-sandbox.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/depend

