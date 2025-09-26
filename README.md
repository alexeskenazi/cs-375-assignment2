# CS-375 Assignment 2: Closest Pair of Points

## Overview

This program finds the closest pair of points using two different algorithms:

1. **Brute Force Algorithm** - O(n²) time complexity
2. **Divide and Conquer Algorithm** - O(n log n) time complexity

## Files Included

- `submission.cpp` - Main program with algorithm implementations
- `point.h` - Point structure and function declarations
- `point.cpp` - Distance calculation and comparison functions
- `file_operations.h` - File I/O function declarations
- `file_operations.cpp` - Functions for reading/writing files
- `makefile` - Build configuration
- `input1.txt`, `input2.txt`, `input3.txt`, `input4.txt` - Test input files

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
./submission input1.txt output1.txt
```

### Run built-in tests and create sample input files

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

Where x and y are coordinates, and z is optional (set to 0 for 2D).

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

The program includes 4 test cases:

1. **Test 1**: Points in decreasing order (n=10000)
2. **Test 2**: Points with coordinates i*i (n=10000)
3. **Test 3**: Points on a negative and postive (maybe a circle?) pattern (n=20000)
4. **Test 4**: Mixed positive/negative coordinates (n=20000)

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

## Performance Comparison

The program shows how much faster the divide and conquer algorithm is compared to brute force. Pretty cool to see the difference!
