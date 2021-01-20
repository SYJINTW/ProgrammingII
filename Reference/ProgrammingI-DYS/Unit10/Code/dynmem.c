#include <stdio.h>
#include <stdlib.h>
#define COLS 5

int main(void)
{
   int i, j, rows=10;
   int *a;//a is a pointer to an int
   int (*b)[COLS];//b is a pointer to a 1-D array of COLS ints

   a = (int *) malloc(rows * sizeof(int));

   for (i = 0; i < rows; i++) a[i] = i;

   b = (int (*)[COLS]) malloc(rows * COLS * sizeof(int));

   for (i = 0; i < rows; i++) {
      for (j = 0; j < COLS; j++) {
         printf("%3d ", (b[i][j]=i*COLS+j));
      }
      printf("\n");
   }

   free(a);
   free(b);

   return 0;
}
