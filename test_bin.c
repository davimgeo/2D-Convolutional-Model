#include <stdio.h>
#include <stdlib.h>

#define ROW 648
#define COLUMN 1150

int main(int argc, char *argv[])
{
  int arr[3][2] = {
      {1, 2},
      {4, 5},
      {7, 8}
  };

  for (int j = 0; j < 2; ++j) 
  {
    for (int i = 0; i < 3; ++i) 
    {
      printf("%d ", arr[i][0]);
    }
    printf("\n");
  }

  return 0;
}

