/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: this program inputs a unknown string without using scanf function and prints the string 
* Author:Yonatan shami
-------------------------------------------------------*/
/*------------------------------------------------------
* Function Name - dyn_scanf
*
* Function Purpose - function that returns the input string using allocated memory
*
* Parameters –  [IN first_parameter - void] 
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
//strlen() is without '\0' and size is with '\0'

char* dyn_scanf(void){
    char *str1=NULL;
    char *str2=NULL;
    size_t size=2;//starting from one char +'\0'. also working for no string at all.
    str1= (char*) malloc(size*sizeof(char));
    if(!str1){//checks memory allocation
        return NULL;
    }
    printf("enter your string: ");//asking for string input
    fgets(str1, size, stdin);

    while('\n' != str1[strlen(str1)-1]){//checking end of string (new line)
        if(size==max-1){
            break;
        }
        size++;
        str2= (char*)realloc(str1, size*sizeof(char));//using second pointer
        if(str2!=NULL){
            str1=str2;
        }else{
            return NULL;
        }
        fgets(str1+strlen(str1), size-strlen(str1), stdin);//to append to the string and not over write what we already have
    }
    //for '\0' we need one more space in memory
    size++;
    str2= realloc(str1, size*sizeof(char));
    if(str2!=NULL){
        str1=str2;
    }else{
        return NULL;
    }
    *(str1+size-1)='\0';//adds end of string
    return str1;

}


int main(){
    char *str=dyn_scanf();
    printf("%s\n", str);
    free(str);
    return 0;
}