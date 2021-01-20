#include <stdio.h>
#define ENGINE 1499.99

int main(void)
{
   printf("~%f~\n", ENGINE);
   printf("~%e~\n", ENGINE);
   printf("~%4.2f~\n", ENGINE);
   printf("~%3.1f~\n", ENGINE);
   printf("~%10.3f~\n", ENGINE);
   printf("~%-10.3f~\n", ENGINE);
   printf("~%12.3e~\n", ENGINE);
   printf("~%+4.2f~\n", ENGINE);
   printf("~%010.2f~\n", ENGINE);

   return 0;
}
