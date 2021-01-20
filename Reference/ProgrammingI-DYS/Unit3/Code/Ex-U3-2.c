#include <stdio.h>
#include <string.h>

int main(void)
{
   printf("The length of string \"%s\" is %d, but %d bytes are occupied.\n",
      "Stevie", strlen("Stevie"), sizeof("Stevie"));

   return 0;
}
