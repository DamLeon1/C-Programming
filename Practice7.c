Problem 24:
#include <stdio.h>


typedef enum {
    ELECTRONICS, GROCERY, CLOTHING
} Category;


typedef struct {
    int id;
    char name[50];
    double price;
    int stockQuantity;
    Category category;
} Product;


int restockProduct(Product *inventory, int count, int targetID, int addQuantity);
void printLowStock(const Product *inventory, int count, int threshold);


int main() {


    Product product[3] = {{1, "hat", 22.50, 10, CLOTHING}, {2, "glasses", 30.00, 50, CLOTHING}, {3, "phone", 140.70, 2, ELECTRONICS}};


    int result = restockProduct(product, 3, 1, 5);


    printLowStock(product, 3, 15);


    return 0;
}


int restockProduct(Product *inventory, int count, int targetID, int addQuantity) {
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == targetID) {
            inventory[i].stockQuantity += addQuantity;
            return 1;
        }
    }
    return 0;
}


void printLowStock(const Product *inventory, int count, int threshold) {
    for (int i = 0; i < count; i++) {
        if (inventory[i].stockQuantity < threshold) {
            printf("Name: %s\nPrice: %.2f\n", inventory[i].name, inventory[i].price);
        }
    }
}

Problem 25:
#include <stdio.h>
#include <stdlib.h>


typedef enum {
    INFO, WARNING, ERROR
} LogLevel;


typedef struct {
    int timestamp;
    LogLevel level;
    char message[100];
} LogEntry;


int main() {


    FILE *fp = fopen("server.log", "r");
    if (fp == NULL) {
        printf("Error opening file");
        return 1;
    }


    int capacity = 2;
    int count = 0;


    LogEntry *log = malloc(capacity * sizeof(LogEntry));
    if (log == NULL) {
        printf("Error in allocation");
        fclose(fp);
        return 1;
    }


    LogEntry temp;
    int tempLevel;


    while (fscanf(fp, "%d, %d, %99[^\n]", &temp.timestamp, &temp.level, &temp.message) == 3) {
        temp.level = (LogLevel)tempLevel;


        if (temp.level == WARNING || temp.level == ERROR) {
       
        if (count == capacity) {
            capacity *= 2;
            LogEntry *realloc_ptr = realloc(log, capacity * sizeof(LogEntry));
            if (realloc_ptr == NULL) {
                printf("Reallocation failed\n");
                free(log);
                fclose(fp);
                return 1;
            }
            log = realloc_ptr;
        }
        log[count] = temp;
        count++;
    }
}


    const char *levelNames[] = {"INFO", "WARNING", "ERROR"};
    printf("--- Filtered Logs (%d captured) ---\n", count);
    for (int i = 0; i < count; i++) {
        printf("[%d] Level: %-7s | Msg: %s\n",
               log[i].timestamp,
               levelNames[log[i].level],
               log[i].message);
    }


    free(log);
    fclose(fp);


    return 0;
}

Problem 26:
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int id;
    double amount;
} Transaction;


double calculateTotalBalance(const Transaction *list, int count);


int main() {


    FILE *fp1 = fopen("ledger.txt", "r");
    if (fp1 == NULL) {
        printf("Error opening ledger.txt\n");
        return 1;
    }


    int capacity = 2;
    int count = 0;


    // FIX 1: Use malloc for initial allocation
    Transaction *list = malloc(capacity * sizeof(Transaction));
    if (list == NULL) {
        printf("Memory allocation failed\n");
        fclose(fp1);
        return 1;
    }


    // FIX 2: Read directly into list[count]
    while (fscanf(fp1, "%d %lf\n", &list[count].id, &list[count].amount) == 2) {
        count++;


        // FIX 3: Correct realloc logic & capacity update
        if (count == capacity) {
            capacity *= 2;
            Transaction *temp = realloc(list, capacity * sizeof(Transaction));
            if (temp == NULL) {
                printf("Memory reallocation failed\n");
                free(list);
                fclose(fp1);
                return 1;
            }
            list = temp;
        }
    }


    FILE *fp2 = fopen("statement.txt", "w");
    if (fp2 == NULL) {
        printf("Error creating statement.txt\n");
        free(list);
        fclose(fp1);
        return 1;
    }


    // FIX 4: Loop through list and print to file
    for (int i = 0; i < count; i++) {
        fprintf(fp2, "ID: %d | Amount: $%.2f\n", list[i].id, list[i].amount);
    }
   
    double total = calculateTotalBalance(list, count);
    fprintf(fp2, "=========================\nTotal Balance: $%.2f\n", total);


    printf("Statement generated successfully with %d transactions!\n", count);


    free(list);
    fclose(fp1);
    fclose(fp2);


    return 0;
}


double calculateTotalBalance(const Transaction *list, int count) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += (list + i)->amount; // Pointer arithmetic works great!
    }
    return sum;
}


