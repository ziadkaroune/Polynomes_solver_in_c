#include "main.h"

int main(int ac , char *av[])
{
    char input[128];
    char *equation = NULL;
     int  eqt_degree;

    t_poly coeffi = {false , 0 , 0 , 0 , 0};
    eqt_degree = 0;

    if(ac > 2){
        printf("error arguments !\nExample : 5 * X^0 + 4 * X^1 = 4 * X^0\n");
        return -1;
    }
    else{
        if (ac == 1) {
            if (fgets(input, sizeof(input), stdin)) {
                input[strcspn(input, "\n")] = 0; 
                equation = input;
            }
        }
         else equation = av[1];
    }
   
    if(!isPolynome(equation)){
        printf("invalid equation");
        return -1;
    }

    // intermediate form
     char *recycle_form = recycle_Polynome(equation , &coeffi);
      eqt_degree  = find_eqaution_degree(&coeffi);
      if(eqt_degree > 0)
            printf("Before Reduced form : %s\n" , recycle_form);
      else
            printf("Reduced form : %s\n" , recycle_form);


   if(coeffi.heigher_degree){
        printf("The polynomial degree is strictly greater than 2, I can't solve\n"); 
        return 0;
   }
    
   char *reduced_form = reducedForm(&coeffi , 300);
    if(eqt_degree > 0)
        printf("%s \n" , reduced_form);

   if(eqt_degree > 0)
        printf("Polynomial degree : %d\n" , eqt_degree);
   equation_solver(&coeffi , eqt_degree);

   free(recycle_form);
   free(reduced_form);
   return 0;
}
