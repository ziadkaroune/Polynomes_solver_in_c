#include "../main.h"

// verify syntaxe error ( more than equal)
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


int find_eqaution_degree(t_poly *coeffi){
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

double ft_fabs(double n) {
    return (n < 0 ? -n : n);
}

double ft_sqrt(double n) {
    if (n < 0) return -1; 
    if (n == 0 || n == 1) return n;

    double precision = 0.000001; 
    double root = n;
    double temp = 0;

    while (ft_fabs(root - temp) > precision) {
        temp = root;
        root = (n / temp + temp) / 2;
    }
    return root;
}

int ft_atoi(const char *str) {
    int res = 0;
    while (*str >= '0' && *str <= '9') {
        res = res * 10 + (*str - '0');
        str++;
    }
    return res;
}
