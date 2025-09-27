# CS-375 Assignment 2: Closest Pair of Points

## Overview

This program finds the closest pair of points in 3D space using two different algorithms:

1. **Brute Force Algorithm** - O(n²) time complexity
2. **Divide and Conquer Algorithm** - O(n log n) time complexity

## Files Included

- `submission.cpp` - Main program with algorithm implementations
- `point.h` - Point structure and function declarations
- `point.cpp` - Distance calculation and comparison functions
- `file_operations.h` - File I/O function declarations
- `file_operations.cpp` - Functions for reading/writing files
- `makefile` - Build configuration
- `input2D-*.txt`, `input3D-*.txt` - Test input files for 2D and 3D modes

## Compilation

To compile the program, run:

```
make
```

To clean object files:

```
make clean
```

## Usage

### Run with input/output files

```
./submission <input_file> <output_file>
```

Example:

```
./submission input3D-1.txt output1.txt
```

### Run built-in tests (creates both 2D and 3D input files)

```
./submission test
```

### Run all test cases

```
make run
```

## Input Format

The input file should contain points in the following format:

```
x1 y1 (z1)
x2 y2 (z2)
...
```

Where x, y, and z are the coordinates. The z-value is in parentheses like the assignment sample shows.

## Output Format

The output file contains:

```
i j D
```

Where:

- `i` = index of first point
- `j` = index of second point  
- `D` = minimum distance between points i and j

## Test Cases

The program has 4 test cases that create both 2D and 3D versions:

1. **Test 1**: Diagonal points going down (n=10000)
2. **Test 2**: Points with squared coordinates (n=10000)
3. **Test 3**: Some kind of circle/spiral pattern (n=20000)
4. **Test 4**: Mix of positive and negative coordinates (n=20000)

## Algorithm Details

### Brute Force

- Checks all possible pairs of points
- Time Complexity: O(n²)
- Simple nested loop implementation

### Divide and Conquer

- Recursively divides points into left and right halves
- Finds closest pairs in each half
- Checks strip between halves for closer pairs
- Time Complexity: O(n log n)
- A great short video explaining the algo can be found here [Closest Pair of Points (Divide and Conquer) Explained](https://www.youtube.com/watch?v=6u_hWxbOc7E)

## Performance Comparison

The program shows how much faster the divide and conquer algorithm is compared to brute force. Pretty cool to see the difference!
