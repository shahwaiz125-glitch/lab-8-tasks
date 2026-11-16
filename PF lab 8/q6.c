#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    do {
        printf("Enter the number of days (1 to 10): ");
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            n = 0;
        }
    } while (n < 1 || n > 10);

    double *temp = (double *)malloc(n * sizeof(double));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Enter temperature for Day %d (-10 to 55): ", i + 1);
            if (scanf("%lf", &temp[i]) == 1 && temp[i] >= -10 && temp[i] <= 55) {
                break;
            }
            printf("Invalid input. Temperature must be between -10 and 55.\n");
            while (getchar() != '\n');
        }
    }

    printf("\n--- Recorded Temperatures --- \n");
    for (int i = 0; i < n; i++) {
        printf("Day %d: %.1f at address %p\n", i + 1, temp[i], (void *)&temp[i]);
    }

    double *ptr = temp;
    double hottest = *ptr;
    double coldest = *ptr;

    for (int i = 0; i < n; i++) {
        if (*ptr > hottest) {
            hottest = *ptr;
        }
        if (*ptr < coldest) {
            coldest = *ptr;
        }
        ptr++;
    }

    printf("\nHottest temperature: %.1f\n", hottest);
    printf("Coldest temperature: %.1f\n", coldest);

    int hotterCount = 0;
    ptr = temp;
    for (int i = 0; i < n; i++) {
        if (*ptr > 40.0) {
            hotterCount++;
        }
        ptr++;
    }
    printf("Number of days hotter than 40: %d\n", hotterCount);

    free(temp);
    temp = NULL;

    printf("\nMemory has been successfully released and pointer set to NULL.\n");

    return 0;
}