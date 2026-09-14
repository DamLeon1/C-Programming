Problem 6:
#include <stdio.h>


float Deposit(float currentBalance){
    float deposit = 0.0f;
    printf("Enter Deposit amount: ");
    scanf("%f", &deposit);


    return deposit + currentBalance;
}


float Withdraw(float currentBalance) {
    float withdraw = 0.0f;
    printf("Enter Withdraw amount: ");
    scanf("%f", &withdraw);


    if (withdraw > currentBalance) {
        printf("Insufficient funds. \n");
        return currentBalance;
    }


    return currentBalance - withdraw;
}


int main() {


    int option = 0;
    float current = 1000.00f;


    printf("Your current balance is $1000.00\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);


    switch(option) {
        case 1:
            printf("Balance: $%.2f", current);
            break;
        case 2:
            current = Deposit(current);
            printf("Balance now $%.2f", current);
            break;
        case 3:
            current = Withdraw(current);
            printf("Balance now $%.2f", current);
            break;
        case 4:
            printf("Exiting");
            break;
        default:
            printf("Invalid");
    }


    return 0;
}

Problem 7:
#include <stdio.h>


double calculateTicketPrice(int age, char dayType, int isStudent){


    double price = 12.0;
   
    if (age < 12 || age >= 65) {
        price *= 0.5;
    }
    else if ((dayType == 'W' || dayType == 'w') && isStudent == 1) {
        price *= 0.75;
    }
    if (dayType == 'S' || dayType == 's') {
        price = 2.0 + price;
    }


    return price;
}

int main() {

    int age = 0;
    char dayType = '\0';
    int isStudent = 0;
    double price = 0.0;

    printf("Ticket Price Calculator\n");
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter type of day (W or S): ");
    scanf(" %c", &dayType);
    printf("Enter if your a student or not (1 or 0): ");
    scanf("%d", &isStudent);

    price = calculateTicketPrice(age, dayType, isStudent);

    printf("%.2f", price);

    return 0;
}
