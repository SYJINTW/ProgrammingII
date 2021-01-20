#include <stdio.h>

void change(int ** ppi, int * pi2);

int main(void)
{
   int y = 2, z = 5;
   int * pi;

   printf("y: %p, %d\n",&y,y);
   printf("z: %p, %d\n\n",&z,z);

   pi = &y;

   printf("Before calling change(), pi points to %p.\n", pi);

   change(&pi, &z);

   printf("After calling change(), pi points to %p.\n", pi);

   return 0;
}
void change(int ** ppi, int * pi2)
{
   *ppi = pi2;
}
