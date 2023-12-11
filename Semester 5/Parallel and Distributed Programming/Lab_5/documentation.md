# Polynomial Multiplication Benchmark

This C++ program compares the performance of different polynomial multiplication algorithms: regular multiplication, parallel multiplication, and Karatsuba algorithm (both sequential and parallel).

## Dependencies

- `iostream`: Standard Input/Output stream.
- `chrono`: Library for time-related operations.
- `vector`: Dynamic array container.
- `thread`: Library for multithreading.
- `mutex`: Mutual exclusion synchronization primitive.
- `random`: Library for generating random numbers.

## Constants

- `TASK_NUM`: Number of threads for parallel multiplication.
- `POLY_SIZE`: Size of the polynomials.
- `MAX_DEPTH`: Maximum depth for parallel Karatsuba algorithm.

## Functions

### 1. `multiply_regular`

Regular polynomial multiplication using nested loops.

### 2. `multiply_parallel`

Polynomial multiplication with parallelization using threads.

### 3. `mod`

Function to perform modular arithmetic.

### 4. `multiply_poly`

Function to multiply two polynomials.

### 5. `karatsuba`

Sequential implementation of the Karatsuba algorithm.

### 6. `karatsuba_parallel`

Parallelized version of the Karatsuba algorithm.

### 7. `measureTime`

Function to measure the execution time of a given function.

## Main Function

The `main` function generates two random polynomials of size `POLY_SIZE`, then measures and prints the execution time of regular multiplication, parallel multiplication, sequential Karatsuba multiplication, and parallel Karatsuba multiplication.

## Usage

1. Compile the program: `g++ filename.cpp -o output_filename -pthread`
2. Run the compiled executable: `./output_filename`
