Problem 9:
#include <stdio.h>


void printCollatzSequence(int start);


int main() {


    int start = 0;


    printf("Enter a positive starting integer: ");
    scanf("%d", &start);


    printCollatzSequence(start);


    return 0;
}


void printCollatzSequence(int start) {
    while (start != 1) {
        if (start % 2 == 0){
             start = start / 2;
        }
        else if (start % 2 != 0){
             start = (start * 3) + 1;
        }
        printf("%d ", start);
    }
}



Problem 10:
#include <stdio.h>


long long calculateFactorial(int n);
void printMultiples(int base, int limit);


int main() {


    char tool = '\0';
    printf("Enter which tool you want to use (F or M): ");
    scanf(" %c", &tool);


    int base = 0;
    int limit = 0;
    int n = 0;


    switch(tool) {
        case 'F':
            printf("Enter a number: ");
            scanf("%d", &n);
            long num = calculateFactorial(n);
            printf("%d ", num);
            break;
        case 'M':
            printf("Enter a base number: ");
            scanf("%d", &base);
            printf("Enter a limit number: ");
            scanf("%d", &limit);
            printMultiples(base, limit);
            break;
        default:
            printf("Error, enter something valid");
    }


    return 0;
}


long long calculateFactorial(int n) {
    long long num = 1;
    for (int i = 1; i <= n; i++) {
        num *= i;
    }
    return num;
}


void printMultiples(int base, int limit) {
    for (int i = base; i <= limit * base; i+=base) {
        printf("%d ", i);
    }
}

Problem 11:
#include <stdio.h>


int getValidScore(void);


int main() {


    int score = 0;
    int sum = 0;
    int count = 0;


    // Get the first score
    score = getValidScore();


    // Loop until the user enters -1
    while (score != -1) {
        sum += score;   // Add to running total
        count++;        // Increment count of scores
        score = getValidScore(); // Get the next score
    }


    // Calculate and print average (be careful of division by zero!)
    if (count > 0) {
        double average = (double)sum / count; // Cast to double for decimal precision
        printf("\nYou entered %d valid scores.\n", count);
        printf("The average score is: %.2lf\n", average);
    } else {
        printf("\nNo scores were entered.\n");
    }


    return 0;
}


int getValidScore(void) {
   
    int score = 0;
   
    while (1) { // Loop forever until we manually return
        printf("Enter a score between 0 and 100 (-1 to exit): ");
        scanf("%d", &score);


        if (score == -1 || (score >= 0 && score <= 100)) {
            return score; // Immediately exit the function and return the valid score
        }
       
        printf("Invalid score! Try again.\n");
    }
}

Problem 12:
#include <stdio.h>


double calculateAverage(double temps[], int size);
double findMax(double temps[], int size);
double findMin(double temps[], int size);


int main() {


    double days[7];
    int size = 7;


    for (int i = 0; i < size; i++) {
        printf("Enter the temperature for day %d: ", i+1);
        scanf("%lf", &days[i]);
    }


    double avg = calculateAverage(days, size);
    double Max = findMax(days, size);
    double Min = findMin(days, size);


    printf("%.2f", avg);


    return 0;
}


double calculateAverage(double temps[], int size) {


    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += temps[i];
    }
    double avg = sum / size;
    return avg;
}


double findMax(double temps[], int size) {


    double max = temps[0];
    for (int i = 0; i < size; i++) {
        if (temps[i] > max) {
            max = temps[i];    
        }
    }
    return max;
}


double findMin(double temps[], int size) {


    double min = temps[0];
    for (int i = 0; i < size; i++) {
        if (temps[i] < min) {
            min = temps[i];          
        }
    }
    return min;
}

Problem 13:
#include <stdio.h>


void analyzeGrades(int grades[3][4]);


int main() {


    int grades[3][4]; // Rows = student, Columns = grades


    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            printf("Student %d enter grade %d: ", i+1, j+1);
            scanf("%d", &grades[i][j]);
        }
    }


    analyzeGrades(grades);


    return 0;
}


void analyzeGrades(int grades[3][4]) {


    for (int i = 0; i < 3; i++) {
        double sum = 0.0;
        printf("Grades: ");
        for(int j = 0; j < 4; j++) {
            printf("%d ", grades[i][j]);
            sum += grades[i][j];
        }
        printf("\n");


        double result1 = sum / 4.0;
        printf("Average for student %d: %.2f\n\n", i+1 ,result1);
    }
}


