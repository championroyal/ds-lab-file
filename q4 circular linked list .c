#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL, *temp, *pretemp;

void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed! Overflow condition.\n");
        return;
    }

    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;  
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;  
    }
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed! Overflow condition.\n");
        return;
    }

    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;  
    } else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(int data, int position) {
    int i;
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed! Overflow condition.\n");
        return;
    }

    newNode->data = data;

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == tail) {
        tail = newNode;
    }
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("Underflow condition: List is empty.\n");
        return;
    }

    if (head == tail) {
        free(head);
        head = tail = NULL;
    } else {
        temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
    }
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("\nLIST IS EMPTY. NO NODE TO DELETE.\n");
        return;
    }

    if (head == tail) {
        free(head);
        head = tail = NULL;
    } else {
        temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        free(tail);
        tail = temp;
    }
}

void deleteFromPosition(int position) {
    int i;
    if (head == NULL) {
        printf("Underflow condition: List is empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    temp = head;
    for (i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == head) {
        printf("Position out of range.\n");
        return;
    }

    struct Node *nextNode = temp->next->next;
    if (temp->next == tail) {
        tail = temp;
    }
    free(temp->next);
    temp->next = nextNode;
}

int main() {
    int choice, data, position;

    while (1) {
        printf("\nCircular Linked List Operations Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Any Position\n");
        printf("7. Print Linked List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;

            case 4:
                deleteFromBeginning();
                break;

            case 5:
                deleteFromEnd();
                break;

            case 6:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;

            case 7:
                printList();
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
