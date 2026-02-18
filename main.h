#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_poly {
bool   heigher_degree;
double deg_zero ;
double deg_one ;
double deg_two ;
double deg_three;
}       t_poly;

 
//utils
int find_eqaution_degree(t_poly *coeffi);
double ft_fabs(double n);
double ft_sqrt(double n);
int ft_atoi(const char *str);
//logic
void equation_solver(t_poly *coeffi , int poly_degree);
bool isPolynome(char *expression);
char	*recycle_Polynome(char *eqt , t_poly *coeffi);
char *reducedForm(t_poly *coeffi , size_t len_eqt );
