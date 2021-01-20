#include <stdio.h>

int main(void)
{
  int foo = 10, bar = 15;

  asm(
    "add %%ebx,%%eax"
    :"=a"(foo)
    :"a"(foo), "b"(bar)
  );

  printf("foo=%d\n", foo);
  return 0;
}
