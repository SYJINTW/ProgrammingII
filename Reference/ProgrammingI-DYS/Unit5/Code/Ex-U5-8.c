#include <stdio.h>
#define PAR 5
int main(void)
{
   float hours;
   int tired_days = 0;
   int all_days = 0;

   printf("Please enter the hours of sleep per night during the past few days.\n");
   printf("(q to quit): ");
   while (scanf("%f", &hours) == 1) {       
      all_days++;
      if (hours < PAR) {
         tired_days++;  
      }
   }   
   
   if (all_days != 0) 
      printf("%.1f%% of the time you didn't sleep enough.\n", 
         100.0 * (float) tired_days / all_days);        

   if (all_days == 0)  
      printf("No data entered!\n");


   return 0;
}
