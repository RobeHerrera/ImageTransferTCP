# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /snap/clion/34/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/34/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rohe/Documents/ImageTransferTCP/Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rohe/Documents/ImageTransferTCP/Server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/src/demo_Server.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/demo_Server.cpp.o: ../src/demo_Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rohe/Documents/ImageTransferTCP/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server.dir/src/demo_Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/src/demo_Server.cpp.o -c /home/rohe/Documents/ImageTransferTCP/Server/src/demo_Server.cpp

CMakeFiles/Server.dir/src/demo_Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/src/demo_Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rohe/Documents/ImageTransferTCP/Server/src/demo_Server.cpp > CMakeFiles/Server.dir/src/demo_Server.cpp.i

CMakeFiles/Server.dir/src/demo_Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/src/demo_Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rohe/Documents/ImageTransferTCP/Server/src/demo_Server.cpp -o CMakeFiles/Server.dir/src/demo_Server.cpp.s

CMakeFiles/Server.dir/src/node.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/node.cpp.o: ../src/node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rohe/Documents/ImageTransferTCP/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Server.dir/src/node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/src/node.cpp.o -c /home/rohe/Documents/ImageTransferTCP/Server/src/node.cpp

CMakeFiles/Server.dir/src/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/src/node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rohe/Documents/ImageTransferTCP/Server/src/node.cpp > CMakeFiles/Server.dir/src/node.cpp.i

CMakeFiles/Server.dir/src/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/src/node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rohe/Documents/ImageTransferTCP/Server/src/node.cpp -o CMakeFiles/Server.dir/src/node.cpp.s

CMakeFiles/Server.dir/src/socket_manager.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/socket_manager.cpp.o: ../src/socket_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rohe/Documents/ImageTransferTCP/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Server.dir/src/socket_manager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/src/socket_manager.cpp.o -c /home/rohe/Documents/ImageTransferTCP/Server/src/socket_manager.cpp

CMakeFiles/Server.dir/src/socket_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/src/socket_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rohe/Documents/ImageTransferTCP/Server/src/socket_manager.cpp > CMakeFiles/Server.dir/src/socket_manager.cpp.i

CMakeFiles/Server.dir/src/socket_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/src/socket_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rohe/Documents/ImageTransferTCP/Server/src/socket_manager.cpp -o CMakeFiles/Server.dir/src/socket_manager.cpp.s

CMakeFiles/Server.dir/src/tcp_server.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/tcp_server.cpp.o: ../src/tcp_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rohe/Documents/ImageTransferTCP/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Server.dir/src/tcp_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/src/tcp_server.cpp.o -c /home/rohe/Documents/ImageTransferTCP/Server/src/tcp_server.cpp

CMakeFiles/Server.dir/src/tcp_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/src/tcp_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rohe/Documents/ImageTransferTCP/Server/src/tcp_server.cpp > CMakeFiles/Server.dir/src/tcp_server.cpp.i

CMakeFiles/Server.dir/src/tcp_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/src/tcp_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rohe/Documents/ImageTransferTCP/Server/src/tcp_server.cpp -o CMakeFiles/Server.dir/src/tcp_server.cpp.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/src/demo_Server.cpp.o" \
"CMakeFiles/Server.dir/src/node.cpp.o" \
"CMakeFiles/Server.dir/src/socket_manager.cpp.o" \
"CMakeFiles/Server.dir/src/tcp_server.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/src/demo_Server.cpp.o
Server: CMakeFiles/Server.dir/src/node.cpp.o
Server: CMakeFiles/Server.dir/src/socket_manager.cpp.o
Server: CMakeFiles/Server.dir/src/tcp_server.cpp.o
Server: CMakeFiles/Server.dir/build.make
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rohe/Documents/ImageTransferTCP/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server

.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd /home/rohe/Documents/ImageTransferTCP/Server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rohe/Documents/ImageTransferTCP/Server /home/rohe/Documents/ImageTransferTCP/Server /home/rohe/Documents/ImageTransferTCP/Server/cmake-build-debug /home/rohe/Documents/ImageTransferTCP/Server/cmake-build-debug /home/rohe/Documents/ImageTransferTCP/Server/cmake-build-debug/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend

