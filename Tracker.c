#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define flagfile "fiist_run.flag"

int main(){
    double income, expense;
    char inc[11], exp[11];
    char *fp;
    int fplen = 20;
    fp = (char *)malloc(fplen * sizeof(char));
    
    
    fp = fopen(flagfile, "r");
    if(fp == NULL){
        printf("This is your first run.\nThis program will track your fincance\nThe idea is you enter your income and expenses\nAnd the program will track it for you in a  file called  'income' (another file that should not be delete is first_run.flag)\n");
        fp = fopen(flagfile, "w");
        fclose(fp);
        fp = fopen("income", "w");
    }
    else{
        printf("Welcome back!\n");
        fclose(fp);
        fp = fopen("income", "w");
    }
        

}
