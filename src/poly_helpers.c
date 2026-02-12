#include "../main.h"

/// problem wiith degree 2 +

int find_poly_degree(t_poly *coeffi){
    int degree;
    if (coeffi->deg_three != 0)
        degree = 3;
    else if (coeffi->deg_two != 0)
        degree = 2;
    else if (coeffi->deg_one != 0)
        degree = 1;
    else if (coeffi->deg_zero != 0)
        degree = 0;
    else
        degree = -1;

   
    return degree; 
} 