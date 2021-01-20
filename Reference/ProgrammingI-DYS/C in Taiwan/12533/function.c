#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include "function.h"

Point * ones_vec_1(int length)
{
	Point *a;
	a=(Point *)malloc(length*sizeof(Point));
	for(int i=0;i<length;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	return a;
}

float compute_distance(Point* a, int first_id, int second_id)
{
    float ans;
    Point first_p, second_p;
	
	first_p=a[first_id];
	second_p=a[second_id];
	
	ans=sqrt(pow(first_p.x-second_p.x,2)+pow(first_p.y-second_p.y,2));
    
    return ans;
}
