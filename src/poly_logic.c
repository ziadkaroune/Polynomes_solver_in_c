#include "../main.h"




///////////////////////////////////////////
///////Validate polynome expression //////////////

static bool verify_equal(char *expression){
    int oneEqual = 0;
    for(int i = 0 ; expression[i] != '\0' ; i++){
        if(expression[i] == '=')
                oneEqual++;
    }
    if(oneEqual == 1 )
             return true;
    return false;
}
bool isPolynome(char *expression){
    if(!verify_equal(expression))
            return false;
    for(int i = 0 ; expression[i] != '\0' ; i++){
        char c = expression[i];
        if(!((c >= '0' && c <= '9') ||
              c == '=' || c == '*' ||
              c == '.' || c == ' ' ||
              c == '-' ||  c == '+' ||
              c == 'X' ||  c == '^' 
              )){
            return false;  // invalid
        }   
    }
    return true;
}
///////////////////////////////////////////


// poly degree 0 
 void zerodegreepoly(t_poly *coeffi){
     if (coeffi->deg_zero == 0)
        printf("All real numbers are solutions\n");
    else
        printf("No solution (contradiction: %.2f = 0)\n", coeffi->deg_zero);
}
 

/// plynome degree 1
static void premierdegreepoly(t_poly *coeffi){
     double a =   coeffi->deg_one ;
     double z =   coeffi->deg_zero;
     double result =  0 ;
     
     if(a == 0 && z != 0)
        printf("- has no solution \n");
    else if(a == 0 && z == 0)
         printf("- has infinite solutions \n");
    else{
           result = -z/a;
        printf("- solution :  %.2f \n" ,  result);
    }
       
 
}

  

/// plynome degree 2
static void caluclate_determinant(t_poly *coeffi){

      double a =   coeffi->deg_two;
      double b =   coeffi->deg_one ;
      double c =   coeffi->deg_zero;
      
      double determinant = (b * b) - 4 * a * c;    // determinant
      
      if(a == 0) 
                printf("a != 0 pour calculer caulculer les solutions");
      else if(determinant > 0){
          double x1 = (-b - sqrt(determinant) ) / (2 * a);
          double x2 = (-b +  sqrt(determinant)) / (2 * a);
          printf("- Determinant is positive \n the 2 solutions are : %.2f and %.2f \n" , x1 , x2);
      }
            
      else if ( determinant == 0){
          double x  = (-b) / (2 * a);
            printf("- Determinant = 0 has 1 solution x = %.2f \n" ,   x);
      }
          
      else{
           
           double rx1 = ((-b ) / (2 * a)) ;
           double imx1 = - (sqrt(-determinant) / (2 * a) );
            
            double rx2 = ((-b ) / (2 * a)) ;
            double imx2 =  (sqrt(-determinant) / (2 * a) );
         
          printf("- Determinant is negative , has imaginary solutions \n z1 = %.2f + %.2fi \n z2 = %.2f + %.2fi" ,  rx1 , imx1 , rx2 , imx2 );
      }
            
}

// calculate Determinant
void  Check_Determinant(t_poly *coeffi , int poly_degree){
    if (poly_degree == -1) // 0 = 0 
        printf("All real numbers are solutions\n");
    else if(poly_degree == 2)
        caluclate_determinant(coeffi);
    else if(poly_degree == 1)
        premierdegreepoly(coeffi);
    else if (poly_degree == 0)
        zerodegreepoly(coeffi);
    else{
         printf("The polynomial degree is strictly greater than 2, I can't solve");
         return ;
    }
}


