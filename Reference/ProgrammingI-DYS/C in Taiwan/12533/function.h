#ifndef _FUNCTION_H
#define _FUNCTION_H

typedef struct {
    int x;
    int y;
} Point;


Point * ones_vec_1(int length);
float compute_distance(Point* a, int first_id, int second_id);

#endif
