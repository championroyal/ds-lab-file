#include <stdio.h>

void printArray(int arr[], int size) {
	int i;
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array: ");
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtBeginning(int arr[], int *size, int element) {
	int i;
    for ( i = *size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    (*size)++;
}

void insertAtEnd(int arr[], int *size, int element) {
    arr[*size] = element;
    (*size)++;
}

void insertAtPosition(int arr[], int *size, int element, int position) {
	int i;
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    for ( i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

void deleteFromBeginning(int arr[], int *size) {
	int i;
    if (*size == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (i = 0; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteFromEnd(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty.\n");
        return;
    }
    (*size)--;
}

void deleteFromPosition(int arr[], int *size, int position) {
	int i;
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int arr[100];
    int size = 0;
    int choice, element, position;

    while (1) {
        printf("\nArray Operations Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Any Position\n");
        printf("7. Print Array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtBeginning(arr, &size, element);
                break;

            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtEnd(arr, &size, element);
                break;

            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(arr, &size, element, position);
                break;

            case 4:
                deleteFromBeginning(arr, &size);
                break;

            case 5:
                deleteFromEnd(arr, &size);
                break;

            case 6:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteFromPosition(arr, &size, position);
                break;

            case 7:
                printArray(arr, size);
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

