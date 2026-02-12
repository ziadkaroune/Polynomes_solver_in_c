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
            
                        if( *(temp + 1)  == '^' && *(temp + 2) == '2'){
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
                   
            else {
                 res[j++] = temp[i]; 
            }
               
            i++;
    }
    // right side
  
    while (temp[i] == ' ')  // Skip all leading spaces after '='
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

    // (expression)= 0
	res[j++] = ' '; res[j++] = '='; res[j++] = ' '; res[j++] = '0';
	res[j] = '\0';

    //calculate x's
     store_and_calculate_coeff(res , coeffi);
	return (res);
}
