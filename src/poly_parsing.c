#include "../main.h"

static void *store_and_calculate_coeff(char *res , t_poly *coeffi){
    char *ptr = res;
    bool isNegatif ;
    while (*ptr != '\0' && *ptr != '=') 
    {
        isNegatif = false ;
        if(*ptr == '-'){
            isNegatif = true;
            ptr++;
            if(*ptr == ' ')
                ptr++;
        }
               
        if (*ptr == ' ' || *ptr == '+') {
            ptr++;
            continue;
        }

        double val = atof(ptr);
        if(isNegatif)
            val *= -1;
        while ((*ptr >= '0' && *ptr <= '9') || *ptr == '.' )
                ptr++;
        
        char *temp = ptr;

        
        while (*temp == ' ' || *temp == '*')
                 temp++;
       
             if (*temp == 'X') {
                        int exponent = ft_atoi(temp + 2);
                        if( *(temp + 1)  == '^' && exponent > 3){
                                coeffi->heigher_degree = true;
                                break;
                        }
                            
                        else if( *(temp + 1)  == '^' && *(temp + 2) == '3'){
                            coeffi->deg_three += val;
                            ptr = temp + 3;
                        }
                        else if( *(temp + 1)  == '^' && *(temp + 2) == '2'){
                            coeffi->deg_two += val;
                            ptr = temp + 3;
                        }
                        else if( *(temp + 1)  == '^' && *(temp + 2) == '0'){
                            coeffi->deg_zero += val;
                            ptr = temp + 3;
                        }
                        else{
                            coeffi->deg_one += val;
                            ptr = temp + 1;  
                            if (*ptr == '^') ptr += 2; 
                        }
        }
         else 
                coeffi->deg_zero += val;
    }
        return NULL;
}

char	*recycle_Polynome(char *eqt , t_poly *coeffi){

    char	*res;
    int     j ; 
	char	*equal;
 
    int i;
    i = 0;
    j = 0;
 
    
	if (!eqt || !(equal = strchr(eqt, '='))) /// change this to check multiple ==
		return (NULL);
	res = malloc(strlen(eqt) * 2 + 1);
	if (!res) return (NULL);
	
	//left side
    char *temp = eqt;
    while( temp[i]){
            if(temp[i] == '=') {
                 i++; 
                 break;
            } 
            else 
                 res[j++] = temp[i]; 
            i++;
    }
    // right side
  
    while (temp[i] == ' ')  // Skip spaces after '='
        i++;
    
    if (temp[i] != '+' && temp[i] != '-')
        res[j++] = '-';

    while (temp[i] != '\0') {

        if (temp[i] == '+')
            res[j++] = '-';
        else if (temp[i] == '-')
            res[j++] = '+';
        else
            res[j++] = temp[i];

        i++;
    }

	res[j++] = ' '; res[j++] = '='; res[j++] = ' '; res[j++] = '0';
	res[j] = '\0';

    //calculate x's
     store_and_calculate_coeff(res , coeffi);
	return (res);
}

static char handle_sign(double num , bool firstCoef){
    char sign ;
           if(num > 0 && !firstCoef) sign = ' ';
           else if(num > 0) sign = '+';
           else sign = '-';
           return sign;
}

char *reducedForm(t_poly *coeffi , size_t len_eqt ){

    bool isFirst;
    char sign ;
    char codi[40];

    char *store = (char *)malloc(sizeof(char) * (len_eqt * 4 + 128));   
    if (!store)
        return NULL;

    store[0] = '\0';
    isFirst = false;

    strcat(store , "Reduced form : ");
    if(coeffi->deg_three != 0  ){
          isFirst = true;
          sprintf(codi ,"%.1f * X^3 ", ft_fabs(coeffi->deg_three ));
          strcat(store , codi);
        
    }
       if(coeffi->deg_two != 0  ){
          sign = handle_sign(coeffi->deg_two , isFirst);
          sprintf(codi ,"%c %1.f * X^2 ", sign ,ft_fabs(coeffi->deg_two));
          strcat(store , codi);
           isFirst = true;
    }
       if(coeffi->deg_one != 0  ){
          sign = handle_sign(coeffi->deg_one , isFirst);
          sprintf(codi ,"%c %.1f * X ", sign , ft_fabs(coeffi->deg_one) );
          strcat(store , codi);
          isFirst = true;
        
    }
       if(coeffi->deg_zero){
          sign = handle_sign(coeffi->deg_zero , isFirst);
          sprintf(codi ,"%c %.1f ", sign, ft_fabs(coeffi->deg_zero));
          strcat(store , codi);
    }
      strcat(store , " = 0");
    return store;
}


 
