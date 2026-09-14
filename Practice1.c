Problem 1:
#include <stdio.h>


int main() {

    float total = 0.0f;

    printf("What it the total amount in your shopping cart?: ");
    scanf("%f", &total);

    if (total >= 100){
        printf("You have a discount of 10%%.\n");
        total = total - (total * 0.1);
        printf("Your new total is: $%.2f\n", total);
    }
    else {
        printf("Total = $%.2f", total);
    }


    return 0;
}

Problem 2:
#include <stdio.h>


int main() {

    int side1 = 0;
    int side2 = 0;
    int side3 = 0;

    printf("Enter the length of the three sides of the triangle: \n");
    printf("Side 1: ");
    scanf("%d", &side1);


    printf("Side 2: ");
    scanf("%d", &side2);


    printf("Side 3: ");
    scanf("%d", &side3);


    if (side1+side2 > side3 && side1+side3 > side2 && side2+side3 > side1){
        printf("The sides entered are valid for a triangle. \n");
        if (side1 == side2 == side3) {
            printf("The triangle is equilateral.");
        }
        else if (side1 == side2 || side1 == side3 || side2 == side3) {
            printf("The triangle is isosceles.");
        }
        else {
            printf("The triangle is scalene.");
        }
    }
    else {
        printf("The sides entered are not valid for a triangle.");
    }
 
    return 0;
}

Problem 3:
#include <stdio.h>


int main() {


    double num1 = 0.0f;
    double num2 = 0.0f;
    char operator;


    printf("Enter two number and an operator (+, -, *, /)\n");
    printf("Number 1: ");
    scanf("%lf", &num1);
   
    printf("Number 2: ");  
    scanf("%lf", &num2);
   
    printf("Operator: ");
    scanf(" %c", &operator);


    if (operator == '/' && num2 == 0){
        printf("Error: Division by zero is not allowed.\n");
        return 1;
    }
   
    if (operator == '+') {
        printf("%.2f", num1 + num2);
    }
    else if (operator == '-') {
        printf("%.2f", num1 - num2);
    }
    else if (operator == '*') {
        printf("%.2f", num1 * num2);
    }
    else if (operator == '/') {
        printf("%.2f", num1 / num2);
    }
   
    return 0;
}

Problem 4:
#include <stdio.h>
#include <math.h>


int main() {

   int year = 0;

   printf("Enter year: ");
   scanf("%d", &year);


	if (year % 4 == 0) { // Fixed
    if (year % 100 == 0) {
        if (year % 400 == 0) {
            printf("Leap Year (Century Year)\n");
        } else {
            printf("Common Year (Century Year)\n");
        }
    } else {
        printf("Leap Year (Standard)\n");
    }
} else {
    printf("Common Year (Standard)\n");
}
	
   if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
    printf("%d is a leap year.\n", year);
   }
   else {
    printf("%d is not a leap year.\n", year);
   }
   
    return 0;
}

Problem 5:
#include <stdio.h>


int main() {

    double income = 0.0;
    double tax = 0.0;

    printf("Enter Annual Income: ");
    scanf("%lf", &income);

    if (income > 0.0 && income <= 20000.0) {
        printf("Can't be negative and 0 percent tax");
    }
    else if (income > 20000.0 && income <= 50000) {
        tax = income * 0.10;
        printf("10 percent tax = %.2f", tax);
    }
    else if (income > 50000.0) {
        tax = 3000 + income + (income * .20);
        printf("20 percent tax = %.2f", tax);
    }

    return 0;
}
