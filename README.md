# Algorithm Visualizer

This project is an interactive visualization tool for various sorting and graph traversal algorithms.

## Features
### Algorithms
- **Sorting Algorithms:**
  - QuickSort
  - MergeSort
  - BubbleSort
  - InsertionSort
  - SelectionSort
  - HeapSort
  - ShellSort
- **Graph Traversal Algorithms:**
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)

### Visualization Features
- Real-time visualization of algorithm execution
- Color-coded states for better understanding:
  - Current elements being compared
  - Swapped elements
  - Visited nodes in graph traversal
  - Tree edges vs back edges in DFS
- Smooth animations with adjustable playback speed
- Step-by-step execution mode

### User Interface
- Interactive playback controls:
  - Play/Pause button
  - Step forward functionality
  - Speed adjustment (0.25x to 4x)
  - Restart capability
- Clear metrics display:
  - Number of comparisons
  - Number of swaps
  - Progress indicator
  - Current speed
- Keyboard shortcuts:
  - Space: Play/Pause
  - Right Arrow: Step
  - Up/Down Arrows: Adjust Speed
- Tooltips for all controls
- Input validation for menu selections

### Technical Features
- Modular architecture with separate managers for:
  - Animations
  - UI components
  - Input handling
  - Theming
- Robust error handling
- Cross-platform compatibility
- Dynamic array size generation
- Configurable graph structure

## Building the Project
1. Install SFML 2.6.2 and CMake 3.15+
2. Clone the repository
3. Configure with CMake:
   ```bash
   cmake -G "MinGW Makefiles" .
   ```
4. Build the project:
   ```bash
   cmake --build .
   ```

## Usage
1. Run the executable
2. Select an algorithm from the menu (1-10)
3. Use the on-screen controls or keyboard shortcuts to control the visualization
4. Press 'Back' to return to the menu

## Project Structure
- `include/` - Header files
- `src/` - Source files
- `assets/` - Fonts and other resources
  - `fonts/` - Contains OpenSans font files

## Dependencies
- SFML 2.6.2
- CMake 3.15 or higher
- C++17 compatible compiler 