# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build

# Include any dependencies generated for this target.
include CMakeFiles/AlgorithmVisualizer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AlgorithmVisualizer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AlgorithmVisualizer.dir/flags.make

CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/main.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\main.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\main.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\main.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\main.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\main.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\main.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\main.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/Visualizer.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\Visualizer.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\Visualizer.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\Visualizer.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\Visualizer.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\Visualizer.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\Visualizer.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\Visualizer.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/QuickSort.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\QuickSort.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\QuickSort.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\QuickSort.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\QuickSort.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\QuickSort.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\QuickSort.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\QuickSort.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/MergeSort.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\MergeSort.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\MergeSort.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\MergeSort.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\MergeSort.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\MergeSort.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\MergeSort.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\MergeSort.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/BFS.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\BFS.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\BFS.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\BFS.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\BFS.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\BFS.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\BFS.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\BFS.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/DFS.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\DFS.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\DFS.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\DFS.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\DFS.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\DFS.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\DFS.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\DFS.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/BubbleSort.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\BubbleSort.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\BubbleSort.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\BubbleSort.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\BubbleSort.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\BubbleSort.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\BubbleSort.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\BubbleSort.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/AlgorithmFactory.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\AlgorithmFactory.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\AlgorithmFactory.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\AlgorithmFactory.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\AlgorithmFactory.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\AlgorithmFactory.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\AlgorithmFactory.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\AlgorithmFactory.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/Button.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\Button.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\Button.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\Button.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\Button.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\Button.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\Button.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\Button.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/UIManager.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\UIManager.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\UIManager.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\UIManager.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\UIManager.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\UIManager.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\UIManager.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\UIManager.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/InputManager.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\InputManager.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\InputManager.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\InputManager.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\InputManager.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\InputManager.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\InputManager.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\InputManager.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/InsertionSort.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\InsertionSort.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\InsertionSort.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\InsertionSort.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\InsertionSort.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\InsertionSort.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\InsertionSort.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\InsertionSort.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/SelectionSort.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\SelectionSort.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\SelectionSort.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\SelectionSort.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\SelectionSort.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\SelectionSort.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\SelectionSort.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\SelectionSort.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/HeapSort.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\HeapSort.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\HeapSort.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\HeapSort.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\HeapSort.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\HeapSort.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\HeapSort.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\HeapSort.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/ShellSort.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\ShellSort.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\ShellSort.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\ShellSort.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\ShellSort.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\ShellSort.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\ShellSort.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\ShellSort.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/AnimationManager.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\AnimationManager.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\AnimationManager.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\AnimationManager.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\AnimationManager.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\AnimationManager.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\AnimationManager.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\AnimationManager.cpp.s

CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/flags.make
CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/includes_CXX.rsp
CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.obj: C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/src/ThemeManager.cpp
CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.obj: CMakeFiles/AlgorithmVisualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.obj -MF CMakeFiles\AlgorithmVisualizer.dir\src\ThemeManager.cpp.obj.d -o CMakeFiles\AlgorithmVisualizer.dir\src\ThemeManager.cpp.obj -c C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\ThemeManager.cpp

CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\ThemeManager.cpp > CMakeFiles\AlgorithmVisualizer.dir\src\ThemeManager.cpp.i

CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\src\ThemeManager.cpp -o CMakeFiles\AlgorithmVisualizer.dir\src\ThemeManager.cpp.s

# Object files for target AlgorithmVisualizer
AlgorithmVisualizer_OBJECTS = \
"CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.obj" \
"CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.obj"

# External object files for target AlgorithmVisualizer
AlgorithmVisualizer_EXTERNAL_OBJECTS =

AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/main.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/Visualizer.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/QuickSort.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/MergeSort.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/BFS.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/DFS.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/BubbleSort.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/AlgorithmFactory.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/Button.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/UIManager.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/InputManager.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/InsertionSort.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/SelectionSort.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/HeapSort.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/ShellSort.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/AnimationManager.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/src/ThemeManager.cpp.obj
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/build.make
AlgorithmVisualizer.exe: C:/SFML-2.6.2/lib/libsfml-graphics-d.a
AlgorithmVisualizer.exe: C:/SFML-2.6.2/lib/libsfml-window-d.a
AlgorithmVisualizer.exe: C:/SFML-2.6.2/lib/libsfml-system-d.a
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/linkLibs.rsp
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/objects1.rsp
AlgorithmVisualizer.exe: CMakeFiles/AlgorithmVisualizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable AlgorithmVisualizer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AlgorithmVisualizer.dir\link.txt --verbose=$(VERBOSE)
	"C:\Program Files\PowerShell\7\pwsh.exe" -noprofile -executionpolicy Bypass -file C:/vcpkg/scripts/buildsystems/msbuild/applocal.ps1 -targetBinary C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/build/AlgorithmVisualizer.exe -installedDir C:/vcpkg/installed/x64-windows/bin -OutVariable out
	C:\mingw64\bin\cmake.exe -E copy_if_different C:/SFML-2.6.2/bin/sfml-graphics-2.dll C:/SFML-2.6.2/bin/sfml-window-2.dll C:/SFML-2.6.2/bin/sfml-system-2.dll C:/Users/kapil/OneDrive/Desktop/algorithm-visualizer/build

# Rule to build all files generated by this target.
CMakeFiles/AlgorithmVisualizer.dir/build: AlgorithmVisualizer.exe
.PHONY : CMakeFiles/AlgorithmVisualizer.dir/build

CMakeFiles/AlgorithmVisualizer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AlgorithmVisualizer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AlgorithmVisualizer.dir/clean

CMakeFiles/AlgorithmVisualizer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build C:\Users\kapil\OneDrive\Desktop\algorithm-visualizer\build\CMakeFiles\AlgorithmVisualizer.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AlgorithmVisualizer.dir/depend

