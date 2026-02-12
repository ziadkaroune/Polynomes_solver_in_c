#include "main.h"


int main(int ac , char *av[])
{
    t_poly coeffi = {0 , 0 , 0 , 0};
    if(ac != 2 || !isPolynome(av[1])){
        printf("error arguments");
        return -1;
    }
   char *reducedForm = recycle_Polynome(av[1] , &coeffi);
   printf("Reduced form : %s\n" , reducedForm);
   /// fix Reduced Equation
   printf("Reduced Equation: %.2f * X^2 + %.2f * X + %.2f = 0\n", coeffi.deg_two ,   coeffi.deg_one,  coeffi.deg_zero);

   int  poly_degree  = find_poly_degree(&coeffi);
   printf("Polynomial degree : %d\n" , poly_degree);
   
   Check_Determinant(&coeffi , poly_degree);
   
    

    return 0;
}