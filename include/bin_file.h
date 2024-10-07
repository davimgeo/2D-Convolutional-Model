#ifndef BIN_FILE_H
#define BIN_FILE_H

#include <stdio.h>

/**
 * @brief Writes a 2D array to a binary file.
 *
 * This function writes the contents of a 2D array to a binary file.  
 * 
 * @param[in] FILE_PATH Path to the output binary file.
 * @param[in] arr Pointer to the 2D array of any type (e.g., int, float, double).
 * @param[in] type Size of the data type, use sizeof(type).
 * @param[in] row Number of rows in the array.
 * @param[in] column Number of columns in the array.
 *
 * @return void
 *
 * Example usage:
 * @code
 * int arr[3][3] = {
 *     {1, 2, 3},
 *     {4, 5, 6},
 *     {7, 8, 9}
 * };
 * write2D("data/data.bin", arr, sizeof(int), 3, 3);
 * @endcode
 */
void write2D(const char* FILE_PATH, void* arr, size_t type, int row, int column);

/**
 * @brief Reads a 2D binary file into a 2D array.
 *
 * This function reads data from a binary file and fills the given 2D array with the content.
 *
 * @param[in] FILE_PATH Path to the input binary file.
 * @param[out] arr Pointer to the 2D array to be filled with binary file content (e.g., int, float, double).
 * @param[in] type Size of the data type, use sizeof(type).
 * @param[in] row Number of rows in the binary file (known beforehand).
 * @param[in] column Number of columns in the binary file (known beforehand).
 *
 * @return void
 *
 * Example usage:
 * @code
 * int ROW = 648, COLUMN = 1150;
 * float* arr = (float*)malloc(ROW * COLUMN * sizeof(float));
 * read2D("data/data.bin", arr, sizeof(float), ROW, COLUMN);
 * @endcode
 */
void read2D(const char* FILE_PATH, void* arr, size_t type, int row, int column);

/**
 * @brief Writes/creates a 1D binary file from an array.
 * 
 * This function takes a 1D array of any data type (int, float, double, etc.)
 * and writes its contents to a binary file.
 * 
 * @param[in] FILE_PATH Path to the output binary file.
 * @param[out] arr Pointer to the array (of any type) to be written.
 * @param[int] type Size of the data type, use sizeof(type).
 * @param[in] size Number of elements in the array.
 * 
 * @return void
 * 
 * @example
 * int arr[] = {1, 2, 3, 4, 5};
 * int size = sizeof(arr) / sizeof(arr[0]);
 * write1D("data/data.bin", arr, sizeof(int), size);
 */
void write1D(const char* FILE_PATH, void* arr, size_t type, int size);

/**
 * @brief Reads a 1D binary file into an array.
 * 
 * This function reads a binary file containing data of a specific type
 * and stores the data into a provided array.
 * 
 * @param[in] FILE_PATH Path to the input binary file.
 * @param[out] arr Pointer to the array where the file data will be stored.
 * @param[in] type Size of the data type, use sizeof(type).
 * @param[out] size Number of elements in the binary file (this must be known in advance).
 * 
 * @return void
 * 
 * @example
 * int size = 15;
 * int* arr = (int*)malloc(size * sizeof(int));
 * read1D("data/data.bin", arr, sizeof(int), size);
 */
void read1D(const char* FILE_PATH, void* arr, size_t type, int size);

#endif // !BIN_FILE_H
