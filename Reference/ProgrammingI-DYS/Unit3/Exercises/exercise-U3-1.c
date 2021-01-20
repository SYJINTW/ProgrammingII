#include <stdio.h>
#include <float.h>
int main(void)
{
   printf("Number of bits in the mantissa of a float: %d\n", FLT_MANT_DIG);
   printf("Minimum number of significant decimal digits for a float: %d\n", FLT_DIG);
   printf("Minimum value for a positive float retaining full precision: %e\n", FLT_MIN);
   printf("Maximum value for a positive float: %e\n", FLT_MAX);
   printf("Difference between 1.00 and the least float value greater than 1.00: %e\n",
      FLT_EPSILON);
   return 0;
}
