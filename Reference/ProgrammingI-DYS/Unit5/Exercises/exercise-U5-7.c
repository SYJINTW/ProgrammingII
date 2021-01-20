/*

定義一個 function (取名為 check)

檢驗下面的 expression

根據 expression 的值

輸出對應的資訊 "True" 或 "False"

*/


#include <stdio.h>

??? check(???)
{
   ???
}

int main(void)
{
   int x = 5;
   int y = 3;

   check(x > 2 && y == 3);
   check( !(x < 2 || y == 3) );
   check(x != 0 && y);
   check(x == 0 || !y);
   check(x != y && (20/x) < y);
   check( !(y>5 || y<2) && !(x%5) );
   check(!x && x);

   return 0;
}
