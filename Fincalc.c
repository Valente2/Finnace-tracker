#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//This is only for calcutastions, not for tracking thast would be in tracker.c 


int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Enter your calcution such as:\n-debt  (Enter your income and expences to find out wheter you are in debt)\n-bond (Enter money put in, and interst rate(per year) and length)\n -mortgage (Enter the house price, down payment, interst rate(per year) and length)\n -loan (Enter the loan amount, interst rate(per year) and length)\n");
        return 1;
    }
    if(argc < 2) {
        printf("Not enough arguments\n");
        return 0;
    }
    if(strcmp(argv[1], "-debt") == 0) {
        if(argc != 4) {
            printf("Not enough arguments for debt calculation\n");
            return 1;
        }
        double income = atof(argv[2]);
        double expenses = atof(argv[3]);
        double debt = expenses - income;
        if(income > expenses) {
            printf("You are not in debt\n");
        } else {
            printf("Uh-oh you are in debt :(\n");
            printf("Your debt amount is: %.2f\n", debt);
        }
        return 0;
    }
    if(strcmp(argv[1], "-bond") == 0) {
        if(argc != 5) {
            printf("Not enough arguments for bond calculation\n");
            return 1;
        }
        double principal = atof(argv[2]);
        double annual_rate = atof(argv[3]) / 100.0;
        double years = atof(argv[4]);
        double monthly_rate = annual_rate / 12.0;
        double months = years * 12.0;
        double payment = (principal * monthly_rate) / (1 - pow(1 + monthly_rate, -months));
        printf("Your monthly bond payment is: %.2f\n", payment);
        return 0;
    }
    if(strcmp(argv[1], "-mortgage") == 0) {
        if(argc != 6) {
            printf("Not enough arguments for mortgage calculation\n");
            return 1;
        }
        double house_price = atof(argv[2]);
        double down_payment = atof(argv[3]);
        double annual_rate = atof(argv[4]) / 100.0;
        double years = atof(argv[5]);
        double principal = house_price - down_payment;
        double monthly_rate = annual_rate / 12.0;
        double months = years * 12.0;
        double payment = (principal * monthly_rate) / (1 - pow(1 + monthly_rate, -months));
        printf("Your monthly mortgage payment is: %.2f\n", payment);
        if(down_payment < house_price * 0.2) {
            printf("Warning: Your down payment is less than 20%% of the house price. You may need to pay for private mortgage insurance (PMI).\n");
        }
        return 0;
    }
}