#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define flagfile "first_run.flag"

double get_last_balance(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0.0; // Default balance if file doesn't exist
    }

    char line[256];
    double last_balance = 0.0;

    while (fgets(line, sizeof(line), file)) {
        char *balance_ptr = strstr(line, "Balance:");
        if (balance_ptr) {
            sscanf(balance_ptr, "Balance: %lf", &last_balance);
        }
    }

    fclose(file);
    return last_balance;
}

int main() {
    double income, expense, cbalence;
    char inc[11], exp[11], date[9], loan[2];
    FILE *fp;
    fp = fopen(flagfile, "r");
    if (fp == NULL) {
        printf("This is your first run.\nThis program will track your finance.\n");
        printf("The idea is you enter your income and expenses,\nand the program will track it for you in a file called 'income'.\n");
        printf("(Another file that should not be deleted is 'first_run.flag')\n");
        fp = fopen(flagfile, "w");
        fclose(fp);
        fp = fopen("income", "a");
    } else {
        printf("Welcome back!\n");
        fclose(fp);
        fp = fopen("income", "a");
    }

    // Get the last balance
    cbalence = get_last_balance("income");
    printf("Your previous balance: %.2f\n", cbalence);

    printf("Enter income: ");
    fgets(inc, 11, stdin);
    income = atof(inc);
    printf("Enter spendings: ");
    fgets(exp, 11, stdin);
    expense = atof(exp);
    printf("Enter date (DDMMYYYY): ");
    fgets(date, 9, stdin);


    double new_balance = cbalence + income - expense;
    fprintf(fp, "Income: %.2f\nExpense: %.2f\nBalance: %.2f\n", income, expense, new_balance);
    printf("Data saved to file 'income'\n");
    printf("Income: %.2f\nExpense: %.2f\nBalance: %.2f\n", income, expense, new_balance);
    fprintf(fp, "Date of entry: %s\n\n", date);
    fclose(fp);
    printf("Have you taken out a loan recently (Y/N) ");
    fgets(loan, 2, stdin);
    if (loan[0] != 'Y' && loan[0] != 'N') {
        printf("Invalid input. Please enter Y or N.\n");
        return 1;
    }
    if (loan[0] == 'Y') {
        fprintf(fp, "Loan taken out on: %s\n\n", date);
        printf("Loan entry recorded.\n");
    }
    return 0;
}
