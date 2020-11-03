#include <stdlib.h>
#include <stdio.h>
#include <string.h>




void cPrint(void){
    printf("cfunk Aufruf");


    FILE *fp;
    char name[50];
    int roll_no,  i, n;
    float marks;
 
    fp = fopen("marks.txt", "w");
 
 

    fprintf(fp, "test123");
 

 
    fclose(fp); 


}

void cPara(int a){

    
    printf("cPara: Aufruf %i", a);

    

    
}

void cString(char a[]){
    printf("cString: Aufruf %s", a);



}
