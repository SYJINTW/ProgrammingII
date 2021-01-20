#include <stdio.h>

void insertion_sort(int *, int);
void bubble_sort(int *, int);

int data[100000]; /* global array */

int main(void)
{
    int num_data, i;

    FILE *fin, *fout;

    fin = fopen("data_50000.txt", "r");

    /* 先讀出第一個數字 知道整個檔案總共包含幾筆資料 把這項資訊儲存在 num_data 中*/

    fscanf(fin, "%d", &num_data);

    /* 依序讀取檔案裏的每一筆資料  把資料存到 data 中*/

    for (i = 0; i < num_data; i++) {
       fscanf(fin, "%d", &data[i]);
    }

    fclose(fin);

    /* Write your code here */
    //insertion_sort(data,num_data);
    bubble_sort(data,num_data);

    /* 把 data 陣列的內容儲存到檔案中 */
    fout = fopen("data_50000_sorted.txt", "w");

    for (i = 0; i < num_data; i++) {
       fprintf(fout, " %d", data[i]);
    }

    fclose(fout);

    return 0;
}

void insertion_sort(int *ap, int n)
{
    int temp;
    int i,j;

    for(i=1;i<=n-1;i++)
    {
        temp=*(ap+i);
        j=i-1;

        while((j>=0) && (*(ap+j)>temp))
        {
            *(ap+j+1)=*(ap+j);
            j--;
        }
        *(ap+j+1)=temp;
    }
}

void bubble_sort(int *list, int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-1-i; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
