#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_poly {
double deg_zero ;
double deg_one ;
double deg_two ;
double deg_three;
}       t_poly;

 

//utils
int find_poly_degree(t_poly *coeffi);
//logic
void equation_solver(t_poly *coeffi , int poly_degree);
bool isPolynome(char *expression);
char	*recycle_Polynome(char *eqt , t_poly *coeffi);