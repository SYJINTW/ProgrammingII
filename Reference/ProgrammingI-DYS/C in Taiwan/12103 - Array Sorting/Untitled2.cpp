#include<stdio.h>
#include<stdlib.h>
#define SIZE 7  //一個7*7的地圖 

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
	{2,2,2,2,2,2,2}};  //迷宮的樣本,2代表牆壁,0代表路徑 
	if(!visit(maze,pt(2,2),pt(6,6))){
		printf("\沒有發現出口\n");
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
	 maze[start.x][start.y] = 1; //走過的路徑設為1 
	 if(!maze[end.x][end.y]&&
	  !(visit(maze,pt(start.x,start.y+1),end)|| //向右走 
	  visit(maze,pt(start.x+1,start.y),end)|| //向下走 
	  visit(maze,pt(start.x,start.y - 1),end)|| //向左走
	  visit(maze,pt(start.x - 1,start.y),end))){
	 	maze[start.x][start.y] = 0; //不能走到出口,則把所走過的路徑還原為0 
	 
	 }	
	}
	return maze [end.x][end.y];


}
 void print(int maze[][SIZE]){
 	          int i, j;
 	          for(i= 0;i<SIZE;i++){
                   for(j = 0;j<SIZE;j++){ //i,j皆小於迷宮範圍 
                   	
                          switch(maze[i][j]){
                                     case 0 : printf(" ");break;  
		                             case 1 : printf(".");break;
		                             case 2 : printf("#");    	
	                  }               	
				   }
		printf("\n");		   	          	
			   }
 }
