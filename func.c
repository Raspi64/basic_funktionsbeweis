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

char cStringpara(s){

    printf(s);
    return s;
}

int cMath(int a, unsigned char op, int b){

    printf("%i : %c : %i", a, op, b);

    return 0;



}

int cParaXY(unsigned char x, unsigned char y){
    int ix = (int) x;
    int iy = (int) y;

    return ix +iy;
}


void cPara(int a){

    
    printf("cPara: Aufruf %i", a);

    

    
}

void cString(char a[]){
    printf("cString: Aufruf %s", a);



}
