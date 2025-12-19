#include <stdio.h>
#include <stdlib.h>

void insertElements(int array[], int *size);
void insertElementAtEnd(int **array, int *size);
void updateElement(int array[], int size);
void deleteElements(int **array, int *size);
void displayElements(int array[], int size);

int main() {
    int size;
    int *array = NULL;

    printf("Enter The Size Of The Array: ");
    scanf("%d", &size);

    array = (int *)malloc(size * sizeof(int));

    insertElements(array, &size); // Fix here: Pass a pointer to 'size'

    int choice = -1; // Initialize choice to a value that's not 0
    do {
        printf("\n1. To Insert An Element At The End Of the Array.\n");
        printf("2. To Update Element In the Array.\n");
        printf("3. To Delete Element In the Array.\n");
        printf("4. To Display Element In the Array.\n");
        printf("0. To Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("The Program Is Successfully Executed.\n");
                break;
            case 1:
                insertElementAtEnd(&array, &size);
                break;
            case 2:
                updateElement(array, size);
                break;
            case 3:
                deleteElements(&array, &size);
                break;
            case 4:
                displayElements(array, size);
                break;
            default:
                printf("Wrong Choice....\n");
                break;
        }
    } while (choice != 0);

    free(array);
    return 0;
}

void insertElements(int array[], int *size) {
    for (int i = 0; i < *size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

void displayElements(int array[], int size) {
    printf("Current Array IS: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertElementAtEnd(int **array, int *size) {
    int element;
    printf("Enter Element To Insert: ");
    scanf("%d", &element);

    (*size)++;
    *array = realloc(*array, (*size) * sizeof(int));
    if (*array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    (*array)[*size - 1] = element;
    printf("Element inserted at the end.\n");
}

void deleteElements(int **array, int *size) {
    if (*size > 0) {
        (*size)--; // Reduce size after deleting an element
        *array = realloc(*array, (*size) * sizeof(int));
        printf("Last Item Is Successfully Removed.\n");
    } else {
        printf("Array is already empty.\n");
    }
}

void updateElement(int array[], int size) {
    int element, index;
    displayElements(array, size);

    printf("Enter index to target: ");
    scanf("%d", &index);

    if (index >= 0 && index < size) {
        printf("Enter Element To Update at index %d: ", index);
        scanf("%d", &element);
        array[index] = element;
        printf("The Value %d is Successfully Replaced At Index %d.\n", element, index);
    } else {
        printf("Wrong index. Please Try Again.\n");
    }
}