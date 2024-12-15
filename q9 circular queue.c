#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Defining maximum size of the queue

int queue[MAX];  // Array to hold queue elements
int front = -1;  // Index of the front element
int rear = -1;   // Index of the rear element

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % MAX == front;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to insert (enqueue) an element into the queue
void insert(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) {  // If it's the first element being added
            front = 0;
        }
        rear = (rear + 1) % MAX;  // Circular increment of rear
        queue[rear] = value;
        printf("Inserted %d into the queue\n", value);
    }
}

// Function to delete (dequeue) an element from the queue
void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot delete element\n");
    } else {
        int deletedValue = queue[front];
        if (front == rear) {  // If there's only one element left
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;  // Circular increment of front
        }
        printf("Deleted %d from the queue\n", deletedValue);
    }
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;  // Circular increment of index
        }
        printf("%d\n", queue[rear]);  // Print the last element
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCIRCULAR QUEUE OPERATIONS MENU:\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
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

