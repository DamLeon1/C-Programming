Problem 14:
#include <stdio.h>
#include <string.h>


typedef char String[50];
typedef String ProductList[10];


int findProduct(ProductList list, int count, const char *searchName);


int main() {


    int products = 0;
    ProductList list;
   
    printf("How many products do you want: ");
    scanf("%d", &products);


    if (products < 0 || products > 10) {
        printf("Error, out of bounds\n");
        return 1; // Stop if input is bad
    }


    for (int i = 0; i < products; i++) {
        printf("Enter product %d: ", i+1);
        scanf("%49s", list[i]);
    }


    String find = {0};
    printf("Enter a product to look for: ");
    scanf("%s", find);


    int result = findProduct(list, products, find);
   
    if (result != -1) {
        printf("Product found at index: %d\n", result);
    }
    else {
        printf("Product not found (%d)\n", result);
    }


    return 0;
}


int findProduct(ProductList list, int count, const char *searchName) {
    for (int i = 0; i < count; i++) {
        if (strcmp(searchName, list[i]) == 0) {
            return i;
        }
    }  
    return -1;
}

Problem 15:
#include <stdio.h>


typedef enum {
    SUNNY, CLOUDY, RAINY, SNOWY
} Condition;


typedef struct {
    float temperature;
    Condition condition;
} WeatherReport;


void printWeather(const WeatherReport *report);


int main() {


    WeatherReport day = {30.1, SNOWY}; // Change the SNOWY to other conditions
    printWeather(&day);


    return 0;
}


void printWeather(const WeatherReport *report) {
    switch (report->condition) {
        case SUNNY:
            printf("Temperature: %.1f degrees, Condition: Sunny", report->temperature);
            break;
        case CLOUDY:
            printf("Temperature: %.1f degrees, Condition: Cloudy", report->temperature);
            break;
        case RAINY:
            printf("Temperature: %.1f degrees, Condition: Rainy", report->temperature);
            break;
        case SNOWY:
            printf("Temperature: %.1f degrees, Condition: Snowy", report->temperature);
            break;
        default:
            printf("Error");
            break;
    }
}

Problem 16:
#include <stdio.h>


typedef enum {
    JUNIOR, MID, SENIOR, MANAGER
} Role;


typedef struct {
    char name[50];
    double salary;
    Role role;
} Employee;


void applyBonus(Employee *emp);


int main() {


    Employee employee = {"John", 70000, JUNIOR};
    applyBonus(&employee);


    return 0;
}


void applyBonus(Employee *emp) {


    switch(emp->role) {
        case JUNIOR:
             emp->salary += emp->salary*.05; // + (.05*emp->salary);
            printf("%s has a 5 percent raise and their salary is now %.2lf ", emp->name, emp->salary);
            break;
        case MID:
            emp->salary = emp->salary*.1; // + (.1*emp->salary);
            printf("%s has a 10 percent raise and their salary is now %.2lf ", emp->name, emp->salary);
            break;
        case SENIOR:
            emp->salary = emp->salary*.15; // + (.15*emp->salary);
            printf("%s has a 15 percent raise and their salary is now %.2lf ", emp->name, emp->salary);
            break;
        case MANAGER:
            emp->salary = emp->salary*.2; // + (.2*emp->salary);
            printf("%s has a 20 percent raise and their salary is now %.2lf ", emp->name, emp->salary);
            break;
        default:
            printf("Error");
            break;
    }
}

Problem 17:
#include <stdio.h>


typedef enum {
    PROBATION, GOOD_STANDING, HONORS
} AcademicStatus;


typedef struct {
    int id;
    char name[50];
    float gpa;
    AcademicStatus status;
} Student;


Student* findStudentByID(Student students[], int count, int targetID);


int main() {


    Student names[3] = {{1, "John", 3.2, HONORS},
                   {2, "Jack", 2.1, PROBATION},
                   {3, "Man", 2.8, GOOD_STANDING}};


    Student *found = findStudentByID(names, 3, 2);
    if (found != NULL) {
        found->status = HONORS;
        printf("%s %.2f %d", found->name, found->gpa, found->status);
    }


    return 0;
}


Student* findStudentByID(Student students[], int count, int targetID) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == targetID){
            return (&students[i]);
        }
    }
    return NULL;
}


