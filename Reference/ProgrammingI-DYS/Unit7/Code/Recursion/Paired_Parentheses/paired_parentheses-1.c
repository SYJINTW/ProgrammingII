#include <stdio.h>
 void show_parenthesis(int n);

 int main(void)
 {
     int n;

     scanf("%d", &n);
     show_parenthesis(n);

     return 0;
 }

 void show_parenthesis(int n)
 {
     if (n>1) {
         if (n%2==1) {
             printf("(");
             show_parenthesis(n-1);
             printf(")*%d",n);
         } else {
             show_parenthesis(n-1);
             printf("+%d", n);
         }
     } else {
         printf("%d", n);
     }
 }
