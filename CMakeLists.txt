cmake_minimum_required(VERSION 3.15)
project(AlgorithmVisualizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Uncomment if you plan to use static SFML libraries.
# set(SFML_STATIC_LIBRARIES ON)

# Set the SFML configuration directory (update this path as needed).
set(SFML_DIR "C:/SFML-2.6.2/lib/cmake/SFML")

find_package(SFML 2 REQUIRED COMPONENTS graphics window system)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/Visualizer.cpp
    ${CMAKE_SOURCE_DIR}/src/QuickSort.cpp
    ${CMAKE_SOURCE_DIR}/src/MergeSort.cpp
    ${CMAKE_SOURCE_DIR}/src/BFS.cpp
    ${CMAKE_SOURCE_DIR}/src/DFS.cpp
    ${CMAKE_SOURCE_DIR}/src/BubbleSort.cpp
    ${CMAKE_SOURCE_DIR}/src/AlgorithmFactory.cpp
    ${CMAKE_SOURCE_DIR}/src/Button.cpp
    ${CMAKE_SOURCE_DIR}/src/UIManager.cpp
    ${CMAKE_SOURCE_DIR}/src/InputManager.cpp

    # NEW: Add the new sorting algorithm source files.
    ${CMAKE_SOURCE_DIR}/src/InsertionSort.cpp
    ${CMAKE_SOURCE_DIR}/src/SelectionSort.cpp
    ${CMAKE_SOURCE_DIR}/src/HeapSort.cpp
    ${CMAKE_SOURCE_DIR}/src/ShellSort.cpp
    # New files for enhancements:
    ${CMAKE_SOURCE_DIR}/src/AnimationManager.cpp
    ${CMAKE_SOURCE_DIR}/src/ThemeManager.cpp
)

add_executable(AlgorithmVisualizer ${SOURCES})

target_link_libraries(AlgorithmVisualizer PRIVATE sfml-graphics sfml-window sfml-system)
