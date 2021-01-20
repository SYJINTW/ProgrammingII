#include<stdio.h>
#include<stdlib.h>
#define SIZE 7  //�@��7*7���a�� 

typedef struct {
	    int x;
	    int y;
        }Point; 

Point pt(int,int);
int visit(int[][SIZE],Point,Point);
void print(int[][SIZE]);
 
int main(void) {
	int maze[SIZE][SIZE]=
	{
	{2,2,2,2,2,2,2},
	{2,0,0,0,0,0,2},
	{2,2,0,0,2,0,2},
	{2,0,0,2,0,2,2},
	{2,2,2,0,0,2,2},
	{2,0,0,0,0,0,2},	
	{2,2,2,2,2,2,2}};  //�g�c���˥�,2�N�����,0�N����| 
	if(!visit(maze,pt(2,2),pt(6,6))){
		printf("\�S���o�{�X�f\n");
	}
	    print(maze);
	    system("pause");
        return 0;      	
}

Point pt(int x , int y){
	       Point p = {x,y};
	       return p;
}
int visit(int maze[][SIZE],Point start,Point end){
	if(!maze[start.x][start.y]){
	 maze[start.x][start.y] = 1; //���L�����|�]��1 
	 if(!maze[end.x][end.y]&&
	  !(visit(maze,pt(start.x,start.y+1),end)|| //�V�k�� 
	  visit(maze,pt(start.x+1,start.y),end)|| //�V�U�� 
	  visit(maze,pt(start.x,start.y - 1),end)|| //�V����
	  visit(maze,pt(start.x - 1,start.y),end))){
	 	maze[start.x][start.y] = 0; //���ਫ��X�f,�h��Ҩ��L�����|�٭쬰0 
	 
	 }	
	}
	return maze [end.x][end.y];


}
 void print(int maze[][SIZE]){
 	          int i, j;
 	          for(i= 0;i<SIZE;i++){
                   for(j = 0;j<SIZE;j++){ //i,j�Ҥp��g�c�d�� 
                   	
                          switch(maze[i][j]){
                                     case 0 : printf(" ");break;  
		                             case 1 : printf(".");break;
		                             case 2 : printf("#");    	
	                  }               	
				   }
		printf("\n");		   	          	
			   }
 }
