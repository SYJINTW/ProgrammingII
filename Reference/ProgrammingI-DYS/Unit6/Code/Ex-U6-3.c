#include <stdio.h>
#include <ctype.h>
int main(void)
{
   char ch;

   printf("Give me a letter of the alphabet, and I will give ");
   printf("an animal name \nbeginning with that letter.\n");

   ch = getchar();

   if (islower(ch)) {
      switch (ch) {
         case 'a':
            printf("argali, a wild sheep of Asia\n");
            break;
         case 'b':
            printf("babirusa, a wild pig of Malay\n");
            break;
         case 'c':
            printf("coati, racoonlike mammal\n");
            break;
         case 'd':
            printf("desman, aquatic, molelike critter\n");
            break;
         case 'e':
            printf("echidna, the spiny anteater\n");
            break;
         case 'f':
            printf("fisher, brownish marten\n");
            break;
         default :
            printf("That's a stumper!\n");
      }
   }
   else {
      printf("I recognize only lowercase letters.\n");
   }

   return 0;
}
