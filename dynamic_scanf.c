/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: this program inputs a string and array of numbers, prints each array character and his address usind pointes. 
* Author:Yonatan shami
-------------------------------------------------------*/
/*------------------------------------------------------
* Function Name - countStr
*
* Function Purpose - void function that counts how many times a string appears in the text.
*
* Parameters –  [IN first_parameter - char * fro, char * str] 
*
* Return Values - 8
*
* Author - Yonatan Shami
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>

#define max UINT_MAX

char* dyn_scanf(void){
    char *str1=NULL;
    char *str2=NULL;
    size_t size=2;//starting from noting '\n'
    str1= (char*) malloc(size*sizeof(char));
    printf("enter your string: ");
    fgets(str1, size, stdin);
    while('\n'!=*(str1+size-1)){
        if(size==max-1){
            break;
        }
        size++;
        str2= (char*)realloc(str1, size*sizeof(char));
        if(str2!=NULL){
            str1=str2;
        }//
        fgets(str1, size, stdin);
    }
    //for '\0' we need one more space in memory
    size++;
    str2= realloc(str1, size*sizeof(char));
    if(str2!=NULL){
        str1=str2;
    }

    free(str2);
    return str1;

}


int main(){
    char *str=dyn_scanf();
    printf("%s\n", *str);
    free(str);
}