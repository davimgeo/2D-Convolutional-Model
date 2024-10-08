#ifndef PRINT_H
#define PRINT_H

/**
 * @brief Prints a 2D array
 *
 * This functions prints 2D arrays of a specific type
 *
 * @param[out] arr Pointer to the array where the file data will be stored.
 * @param[in] type Size of data type, use sizeof(type).
 * @param[in] size Numbers of elements in the array.
 * @param[in] ROW Numbers of rows in the array.
 * @param[in] COLUMN Numbers of columns in the array.
 *
 * @return void
 * 
 * @example
 * int ROW, COLUMN = 3
 * int arr[ROW][COLUMN] = {
 *          {1, 2, 3},
 *          {4, 5, 6},
 *          {7, 8, 9}
 * };
 * 
 * print2D(arr, type, ROW, COLUMN);
*/
void print2D(float* arr, int ROW, int COLUMN);

/**
 * @brief Prints a 1D array.
 *
 * This functions prints 1D arrays of a specific type.
 *
 * @param[out] arr Pointer to the array where the file data will be stored.
 * @param[in] type Size of data type, use sizeof(type).
 * @param[in] size Numbers of elements in the array.
 *
 * @return void
 * 
 * @example
 * int arr[] = {1, 2, 3};
 * int size = sizeof(arr) / sizeof(arr[0]);
 * 
 * print1D(arr, type,);
*/
void print1D(float* arr, int size);

#endif // !PRINT_H

