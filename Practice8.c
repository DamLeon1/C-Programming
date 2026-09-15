Problem 27:
#include <stdio.h>
#include <stdlib.h>


typedef enum {
    TEMPERATURE, HUMIDITY, PRESSURE
} SensorType;


typedef struct {
    int sensorID;
    SensorType type;
    float value;
} SensorReading;


int readSensorData(const char *filename, SensorReading *array, int maxCapacity);


int main() {


    int number = 5;
    SensorReading *SR = malloc(number * sizeof(SensorReading));
    if (SR == NULL) {
        printf("Error allocating memory");
        return 1;
    }


    int num = readSensorData("sensors.txt", SR, 5);
    if (num < 0) {
        printf("Error");
        return 1;
    }


    for (int i = 0; i < num; i++) {
    switch (SR[i].type) {
        case TEMPERATURE :
            printf("%d %d %.2f\n", SR[i].sensorID, SR[i].type, SR[i].value);
            break;
        case HUMIDITY:
            printf("%d %d %.2f\n", SR[i].sensorID, SR[i].type, SR[i].value);
            break;
        case PRESSURE:
            printf("%d %d %.2f\n", SR[i].sensorID, SR[i].type, SR[i].value);
            break;
        default:
            printf("Error");
    }
}


    free(SR);
    return 0;
}


int readSensorData(const char *filename, SensorReading *array, int maxCapacity) {


    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file");
        return -1;
    }


    int count = 0;


    while(count < maxCapacity && fscanf(fp, "%d %d %f", &array[count].sensorID, (int*)&array[count].type, &array[count].value) == 3) {
        count++;
    }


    fclose(fp);
    return count;
}

Problem 28:
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[50];
    float gpa;
} Student;


void swapStudents(Student *a, Student *b);
void sortByGPA(Student *students, int count);


int main() {


    int students = 0;
    printf("Enter how many students: ");
    scanf("%d", &students);


    Student *mem = malloc(students*sizeof(Student));
    if (mem == NULL) {
        printf("Error in allocation");
        return 1;
    }


    for (int i = 0; i < students; i++) {
        printf("Enter student name: ");
        scanf("%49s", mem[i].name);


        printf("Enter student gpa: ");
        scanf("%f", &mem[i].gpa);
    }


    sortByGPA(mem, students);
    printf("\n--- Students Sorted by GPA (Descending) ---\n");
    for (int i = 0; i < students; i++) {
        printf("%d. %-15s | GPA: %.2f\n", i + 1, mem[i].name, mem[i].gpa);
    }


    free(mem);
    return 0;
}


void swapStudents(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}


void sortByGPA(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < count; j++) {
            if (students[i].gpa < students[j].gpa) {
                swapStudents(&students[i], &students[j]);
            }
        }
    }
}

Problem 29:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char key[32];
    char value[64];
} ConfigOption;


const char* getConfigValue(const ConfigOption *options, int count, const char *searchKey);


int main() {


    FILE *fp = fopen("config.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");
        return 1;
    }


    int number = 1;
    ConfigOption *temp = malloc(number*sizeof(ConfigOption));
    if (temp == NULL) {
        printf("Error allocating memory");
        fclose(fp);
        return 1;
    }


    int count = 0;
    while (fscanf(fp, "%31[^=]=%63s\n", temp[count].key, temp[count].value) == 2) {
        count++;


        if(count == number) {
            number *= 2;
            ConfigOption *new = realloc(temp, number*sizeof(ConfigOption));
            if (new == NULL) {
                printf("Error in realloc");
                free(temp);
                fclose(fp);
                return 1;
            }
            temp = new;
        }
    }




    // Safely query and print keys
    const char *hostname = getConfigValue(temp, count, "hostname");
    if (hostname != NULL) {
        printf("hostname: %s\n", hostname);
    } else {
        printf("Key 'hostname' not found.\n");
    }


    const char *debug = getConfigValue(temp, count, "debug_mode");
    if (debug != NULL) {
        printf("debug_mode: %s\n", debug);
    } else {
        printf("Key 'debug_mode' not found.\n");
    }
   
    free(temp);
    fclose(fp);
    return 0;
}


const char* getConfigValue(const ConfigOption *options, int count, const char *searchKey) {
    for (int i = 0; i < count; i++) {
        if (strcmp(searchKey, options[i].key) == 0) {
            return options[i].value;
        }
    }
    return NULL;
}


