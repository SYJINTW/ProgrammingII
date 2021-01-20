#include <stdio.h>

#include <stdlib.h>

/* �w�q�@�ӷs�����O */
/* ���W�s�� Point */
/* �̭��]�t x �M y ��� members */
/* �w�q�L����   Point �i�H�Q���ӷ�@�@�몺���O�Өϥ� */
/* �]�A�ŧi�s���ܼ�   �άO�ŧi function */

typedef struct {
    int x;
    int y;
} Point;

/* ones_vec_1() �|�Ǧ^�Y�� Point ���c����} */
/* �o�Ӧ�}�O�� Point ���c�զ����}�C���}�Y��} */
Point * ones_vec_1(int length);

void ones_vec_2(int length, Point **bp);

int main(void)
{
   Point *a, *b;
   int i, length;

   printf("The size of a Point is %u bytes.\n", sizeof(Point));

   printf("vector length: ");
   scanf("%d", &length);

   /* �Q�� ones_vec_1 ���o�@�Ӱ}�C */
   /* �}�C���C�Ӥ����O�@�� Point */
   /* �}�C���}�Y��}�O���b�����ܼ� a �̭� */
   a = ones_vec_1(length);

   ones_vec_2(length, &b);

   /* a �O�ӫ����ܼ�   ���O�����O�Y�Ӱ}�C���}�Y��} */
   /* �}�C���C�Ӥ����O a[i] (�O�� Point) */
   /* �ҥH����� members  ���O�O a[i].x �M a[i].y */

   for (i=0; i<length; i++)
      printf("(%d, %d) ", a[i].x, a[i].y);
   printf("\n");

   for (i=0; i<length; i++)
      printf("(%d, %d) ", b[i].x, b[i].y);
   printf("\n");

   return 0;
}

Point * ones_vec_1(int length)
{
   Point *a;
   int i;

   a = (Point *) malloc(length * sizeof(Point));

   for (i = 0 ; i < length; i++) {
      a[i].x = 1;
      a[i].y = 1;
   }

   return a;
}

void ones_vec_2(int length, Point **bp)
{
   int i;

   *bp = (Point *) malloc(length * sizeof(Point));

   for (i = 0 ; i < length; i++) {
      (*bp)[i].x = 1;
      (*bp)[i].y = 1;
   }
}
