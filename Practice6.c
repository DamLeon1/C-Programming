Problem 21:
#include <stdio.h>
#include <stdlib.h>


int main() {


    int length = 0;
    printf("Enter maximum number of message (0-200): ");
    scanf("%d", &length);


    if (length < 0 || length > 200) {
        printf("Please enter 0-200 characters");
    }


    char *message = malloc((length + 1) * sizeof(char));
    if (message == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
   
    printf("Enter message: ");
    scanf("%s", message);


    FILE *fp = fopen("log.txt", "a");


    if (fp == NULL) {
        printf("Error opening file");
        free(message);
        return 1;
    }


    fprintf(fp, "%s", message);
    printf("Success");


    fclose(fp);
    free(message);
    message = NULL;


    return 0;
}

Problem 22: when calculating average create a variable then update that using a loop
#include <stdio.h>
#include <stdlib.h>


int main() {


    FILE *fp = fopen("numbers.txt", "r");


    if (fp == NULL) {
        printf("Could not open file");
        return 1;
    }


    int number = 0;
    fscanf(fp, "%d", &number);


    int *count = calloc(number, sizeof(int));
   
    if (count == NULL) {
        printf("Memory allocation failed");
        fclose(fp);
        return 1;
    }


    int sum = 0;
    for (int i = 0; i < number; i++) {
        fscanf(fp, "%d", &count[i]);
        sum += count[i];
    }


    if (number > 0) {
        double average = (double)sum / number;
        printf("Count: %d\n", number);
        printf("Average: %.2f\n", average);
    } else {
        printf("File contains no entries.\n");
    }
   
    fclose(fp);
    free(count);
    count = NULL;


    return 0;
}

Problem 23:
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;


int main() {


    FILE *fp = fopen("students.csv", "r");


    if (fp == NULL) {
        printf("Error opening file");
        return 1;
    }


    int capacity = 2;
    int count = 0;


    Student *students = malloc(capacity * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed");
        fclose(fp);
        return 1;
    }


     while (fscanf(fp, "%d,%49[^,],%f\n", &students[count].id, students[count].name, &students[count].gpa) == 3){
        count++;
        if (count == capacity) {
            capacity *= 2;
            Student *temp = realloc(students, capacity * sizeof(Student));
            if (temp == NULL) {
                free(students);
                fclose(fp);
                return 1;
            }
            students = temp;
        }
    }


    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %-10s | GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }


    free(students);
    fclose(fp);


    return 0;
}



