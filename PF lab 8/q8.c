#include <stdio.h>
#include <stdlib.h>

void printReport(int *arr, int n);
void displayStock(int *arr, int n);
void updateStock(int *arr, int n);
int* insertItem(int *arr, int *n);
int* deleteItem(int *arr, int *n);
void sortStock(int *arr, int n);

int main() {
    int n;
    do {
        printf("Enter starting stock size (3 to 8): ");
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            n = 0;
        }
    } while (n < 3 || n > 8);

    int *stock = (int *)malloc(n * sizeof(int));
    if (stock == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter stock quantity for item %d: ", i + 1);
        while (scanf("%d", &stock[i]) != 1) {
            printf("Invalid input. Enter an integer: ");
            while (getchar() != '\n');
        }
    }

    printReport(stock, n);

    int choice;
    do {
        printf("\n===== BILAL'S GROCERY SHOP MENU =====\n");
        printf("1. Display stock\n");
        printf("2. Update stock of one item\n");
        printf("3. Insert a new item\n");
        printf("4. Delete an item\n");
        printf("5. Sort stock\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                displayStock(stock, n);
                break;
            case 2:
                updateStock(stock, n);
                break;
            case 3:
                stock = insertItem(stock, &n);
                break;
            case 4:
                stock = deleteItem(stock, &n);
                break;
            case 5:
                sortStock(stock, n);
                break;
            case 6:
                if (stock != NULL) {
                    free(stock);
                    stock = NULL;
                }
                printf("\nMemory successfully released. Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

void printReport(int *arr, int n) {
    if (n <= 0) {
        printf("\n--- Stock Report ---\n");
        printf("Stock is currently empty (0 items).\n");
        printf("--------------------\n");
        return;
    }

    int totalStock = 0;
    int lowestStock = *arr;
    int *ptr = arr;

    for (int i = 0; i < n; i++) {
        totalStock += *ptr;
        if (*ptr < lowestStock) {
            lowestStock = *ptr;
        }
        ptr++;
    }

    printf("\n--- Stock Report ---\n");
    printf("Total Stock Quantity: %d\n", totalStock);
    printf("Lowest Stock Value: %d\n", lowestStock);
    printf("--------------------\n");
}

void displayStock(int *arr, int n) {
    if (n == 0) {
        printf("\nStock is empty.\n");
        return;
    }
    printf("\n--- Current Stock Items ---\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: %d\n", i + 1, *(arr + i));
    }
    printf("---------------------------\n");
}

void updateStock(int *arr, int n) {
    if (n == 0) {
        printf("Stock is empty. Nothing to update.\n");
        return;
    }

    int pos, val;
    printf("Enter position to update (1 to %d): ", n);
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > n) {
        printf("Error: Invalid position!\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter new stock value: ");
    if (scanf("%d", &val) != 1) {
        printf("Error: Invalid value!\n");
        while (getchar() != '\n');
        return;
    }

    *(arr + (pos - 1)) = val;
    printf("Stock updated successfully.\n");
    printReport(arr, n); 
}

int* insertItem(int *arr, int *n) {
    int pos, val;
    printf("Enter position to insert new item (1 to %d): ", *n + 1);
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > *n + 1) {
        printf("Error: Invalid position!\n");
        while (getchar() != '\n');
        return arr;
    }

    printf("Enter stock value for the new item: ");
    if (scanf("%d", &val) != 1) {
        printf("Error: Invalid value!\n");
        while (getchar() != '\n');
        return arr;
    }

    int newSize = *n + 1;
    int *newArr = (int *)malloc(newSize * sizeof(int));
    if (newArr == NULL) {
        printf("Memory allocation failed!\n");
        return arr;
    }

    for (int i = 0, j = 0; i < newSize; i++) {
        if (i == pos - 1) {
            *(newArr + i) = val;
        } else {
            *(newArr + i) = *(arr + j);
            j++;
        }
    }

    free(arr); 
    *n = newSize;
    printf("Item inserted successfully.\n");
    printReport(newArr, *n); 
    return newArr;
}

int* deleteItem(int *arr, int *n) {
    if (*n == 0) {
        printf("Stock is empty. Nothing to delete.\n");
        return arr;
    }

    int pos;
    printf("Enter position of item to delete (1 to %d): ", *n);
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > *n) {
        printf("Error: Invalid position!\n");
        while (getchar() != '\n');
        return arr;
    }

    int newSize = *n - 1;
    int *newArr = NULL;

    if (newSize > 0) {
        newArr = (int *)malloc(newSize * sizeof(int));
        if (newArr == NULL) {
            printf("Memory allocation failed!\n");
            return arr;
        }

        for (int i = 0, j = 0; i < *n; i++) {
            if (i == pos - 1) {
                continue; 
            }
            *(newArr + j) = *(arr + i);
            j++;
        }
    }

    free(arr); // Delete old array
    *n = newSize;
    printf("Item deleted successfully.\n");
    printReport(newArr, *n); 
    return newArr;
}

void sortStock(int *arr, int n) {
    if (n <= 1) {
        printf("Stock has 0 or 1 item, already sorted.\n");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int *p1 = arr + j;
            int *p2 = arr + j + 1;
            if (*p1 > *p2) {
                int temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
        }
    }
    printf("Stock sorted in ascending order successfully.\n");
    printReport(arr, n);
}