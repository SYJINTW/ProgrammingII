#include <stdio.h>
#include <stdlib.h>

int main() {
    int H, W, row, col, k;
    int count=0, direction;

    scanf("%d %d", &H, &W);
    scanf("%d %d", &row, &col);
    count+=1;
    scanf("%d", &k);

    direction = 1;

    for(; count<k; count++) {
        if((row==1 || row==H) && (col==1 || col==W)) break;
        if(direction==1) {
            while(1) {
                row--;
                col++;
                if(row==1) {
                    direction = 2;
                    break;
                }
                else if(col==W) {
                    direction = 4;
                    break;
                }
            }
        }
        else if(direction==2) {
            while(1) {
                row++;
                col++;
                if(row==H) {
                    direction = 1;
                    break;
                }
                else if(col==W) {
                    direction = 3;
                    break;
                }
            }
        }
        else if(direction==3) {
            while(1) {
                row++;
                col--;
                if(row==H) {
                    direction = 4;
                    break;
                }
                else if(col==1) {
                    direction = 2;
                    break;
                }
            }
        }
        else if(direction==4) {
            while(1) {
                row--;
                col--;
                if(row==1) {
                    direction = 3;
                    break;
                }
                else if(col==1) {
                    direction = 1;
                    break;
                }
            }
        }
    }

    printf("(%d,%d)", row, col);

    return 0;
}
