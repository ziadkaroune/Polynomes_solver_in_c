#include "../main.h"

// Equations degree 0 
static void zero_degree_eqtion(t_poly *coeffi){
     if (coeffi->deg_zero == 0)
        printf("Any real number is a solution\n");
    else
        printf("No solution.\n");
}
 
///  plynome degree 1 
static void premier_degree_equation(t_poly *coeffi){
     double a =   coeffi->deg_one ;
     double z =   coeffi->deg_zero;
     double result =  0 ;
     
     if(a == 0 && z != 0)
        printf("No solution. \n");
    else if(a == 0 && z == 0)
         printf("Any real number is a solution \n");
    else{
        result = -z/a;
        printf("solution : \n%.2f \n" ,  result);
    }
}

/// plynome degree 2
static void deuxieme_degree_poly(t_poly *coeffi){

      double a =   coeffi->deg_two;
      double b =   coeffi->deg_one ;
      double c =   coeffi->deg_zero;
      
      double determinant = (b * b) - 4 * a * c; //(avec a != 0)
      
      if(determinant > 0){
          double x1 = (-b - ft_sqrt(determinant) ) / (2 * a);
          double x2 = (-b + ft_sqrt(determinant)) / (2 * a);
          printf("Discriminant is strictly positive, the two  solutions are:\n%.2f\n%.2f \n" , x1 , x2);
      }
            
      else if ( determinant == 0){
          double x  = (-b) / (2 * a);
          printf("Determinant = 0  \n  The solution is:\n %.4f \n" , x);
      }
          
      else{
            double rx1 = ((-b ) / (2 * a)) ;
            double imx1 = -(sqrt(-determinant) / (2 * a) );
            double rx2 =   rx1 ;
            double imx2 =  -imx1;
            printf("Discriminant is strictly negative, the two complex solutions are:\n");
            printf("z1 = %.2f + (%.2fi) \n" ,  rx1 , imx1 );
            printf("z2 = %.2f + (%.2fi) \n" , rx2 , imx2 );
      }
}

// calculate Determinant
void  equation_solver(t_poly *coeffi , int poly_degree){
    if (poly_degree == -1) // 0 = 0 
        printf("Any real number is a solution.\n");
    else if(poly_degree == 2)
        deuxieme_degree_poly(coeffi);
    else if(poly_degree == 1)
        premier_degree_equation(coeffi);
    else if (poly_degree == 0)
        zero_degree_eqtion(coeffi);
    else{
         printf("The polynomial degree is strictly greater than 2, I can't solve\n");
         return ;
    }
}
