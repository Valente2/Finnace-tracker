#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Enter your calcution such as:\n-debt  (Enter your income and expences to find out wheter you are in debt)\n-bond (Enter money put in, and interst rate(per year) and length)\n -mortgage (Enter the house price, down payment, interst rate(per year) and length)\n -loan (Enter the loan amount, interst rate(per year) and length)\n");
        return 1;
    }
    if(argc < 2) {
        printf("Not enough arguments\n");
        return 1;
    }
    if(argv[1] == -debt){
        if(argc != 4) {
            printf("Not enough arguments for debt calculation\n");
            return 1;
        }
        double income = atof(argv[2]);
        double expenses = atof(argv[3]);
        if(income > expenses) {
            printf("You are not in debt\n");
        } else {
            printf("Uh-oh you are in debt :(\n");
        }
        return 0;
    }
}