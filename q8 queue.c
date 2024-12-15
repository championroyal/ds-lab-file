#include <stdio.h>
#include <stdlib.h>

#define MAX 10 

int queue[MAX];  
int front = -1;  
int rear = -1;   


int isFull() {
    return rear == MAX - 1;
}


int isEmpty() {
    return front == -1 || front > rear;
}


void insert(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) {
            front = 0; 
        }
        queue[++rear] = value;
        printf("Inserted %d into the queue\n", value);
    }
}


void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete element\n");
    } else {
        int deletedValue = queue[front++];
        printf("Deleted %d from the queue\n", deletedValue);
    }
}


void display() {
	int i;
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQUEUE OPERATIONS MENU:\n");
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert into the queue: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

