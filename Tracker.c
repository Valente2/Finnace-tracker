#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define flagfile "fiist_run.flag"

int main(){
    FILE *fp;
    
    fp = fopen(flagfile, "r");
    if(fp == NULL){
        printf("This is your first run.\nThis program will track your fincance\nThe idea is you enter your income and expenses\nAnd the program will track it for you in a  file called  'fin.txt' (another file that should not be delete is first_run.flag)\n");
        fp = fopen(flagfile, "w");
        fclose(fp);
    }
    else{
        printf("Welcome back!\n");
        fclose(fp);
    }
}