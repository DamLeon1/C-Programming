Problem 18:
#include <stdio.h>
#include <math.h>


typedef struct {
    int x;
    int y;
} Point;


typedef struct {
    Point topLeft;
    Point bottomRight;
} Rectangle;


int calculateArea(const Rectangle *rect);


int main() {


    Rectangle x = { {2,8}, {7,3} };
    int area = calculateArea(&x);
    printf("%d", area);


    return 0;
}


int calculateArea(const Rectangle *rect) {


    int width = abs(rect->bottomRight.x - rect->topLeft.x);
    int height = abs(rect->topLeft.y - rect->bottomRight.y);


    return (width * height);


}

Problem 19:
#include <stdio.h>


typedef enum {
    TODO, IN_PROGRESS, DONE
} TaskState;


typedef struct {
    int id;
    char description[100];
    TaskState state;
} Task;


int advanceTaskState(Task *t);
void printTasks(const Task *taskList, int count);


int main() {


    Task taskList[2] = {{1, "Engineer", TODO} , {2, "Finish code", IN_PROGRESS}};
    int status = advanceTaskState(&taskList[0]);


    printTasks(taskList, 1);


    return 0;
}


int advanceTaskState(Task *t) {
    TaskState status = t->state;


    if (t == NULL) {
        return 0;
    }


    switch (status) {
        case TODO:
            t->state = IN_PROGRESS;
            return 1;
        case IN_PROGRESS:
            t->state = DONE;
            return 1;
        case DONE:
            return 0;
        default:
            return 0;
    }
}


void printTasks(const Task *taskList, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d", (taskList+i)->state);
    }
}

Problem 20:
#include <stdio.h>


typedef enum {
    CHECKING, SAVINGS
} AccountType;


typedef struct {
    int accountNumber;
    double balance;
    AccountType type;
} BankAccount;


int transferFunds(BankAccount *from, BankAccount *to, double amount);


int main() {




    BankAccount acc1 = {1, 500.00, CHECKING};
    BankAccount acc2 = {2, 100.00, SAVINGS};


    int result1 = transferFunds(&acc1, &acc2, 100);
    printf("%d", result1);


    return 0;
}


int transferFunds(BankAccount *from, BankAccount *to, double amount) {
      if (from->balance < amount || amount < 0) {
       // printf("Error insufficient funds");
        return 0;
      }
      else if (amount > 0) {
        from->balance = from->balance - amount;
        to->balance = to->balance + amount;
      }
    return 1;
}


