#include <stdio.h>

// Function prototypes
int findMax(int *p, int n);
int findMin(int *p, int n);
double findAverage(int *p, int n);
int countAbove(int *p, int n, double avg);
void reverseArray(int *p, int n);
int searchMark(int *p, int n, int key);

int main() {
    int marks[10]; // Store the marks of 10 students[cite: 2]

    // 1. Input marks (must be from 0 to 100)[cite: 2]
    for (int i = 0; i < 10; i++) {
        while (1) {
            printf("Enter marks for Student %d (0 to 100): ", i + 1);
            if (scanf("%d", &marks[i]) == 1 && marks[i] >= 0 && marks[i] <= 100) {
                break;
            }
            printf("Invalid input. Marks must be between 0 and 100.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    // 2. Calculate report metrics using the requested functions[cite: 2]
    int maxMark = findMax(marks, 10);
    int minMark = findMin(marks, 10);
    double avgMark = findAverage(marks, 10);
    int aboveAvgCount = countAbove(marks, 10, avgMark);

    printf("\n--- Class Result Report ---\n");
    printf("Highest Mark: %d\n", maxMark);
    printf("Lowest Mark: %d\n", minMark);
    printf("Average Mark: %.2f\n", avgMark);
    printf("Students scoring above average: %d\n", aboveAvgCount);

    // 6. Print pass count (pass means 40 or more)[cite: 2]
    int passCount = 0;
    for (int i = 0; i < 10; i++) {
        if (marks[i] >= 40) {
            passCount++;
        }
    }
    printf("Pass Count (40 or more): %d\n", passCount);

    // 5. Print the array before reversing[cite: 2]
    printf("\nMarks before reversing:\n");
    for (int i = 0; i < 10; i++) {
        printf("Roll %d: %d\n", i + 1, marks[i]);
    }

    // 3. Reverse the array using two pointers[cite: 2]
    reverseArray(marks, 10);

    // 5. Print the array after reversing[cite: 2]
    printf("\nMarks after reversing (from last roll number to first):\n");
    for (int i = 0; i < 10; i++) {
        printf("Position %d: %d\n", i + 1, marks[i]);
    }

    // 4. Search for a particular mark[cite: 2]
    int key;
    printf("\nEnter a mark to search for: ");
    scanf("%d", &key);
    int position = searchMark(marks, 10, key);
    if (position != -1) {
        printf("Mark %d found at index position %d.\n", key, position);
    } else {
        printf("Mark %d not found (-1).\n", key);
    }

    return 0;
}

// Function definitions
int findMax(int *p, int n) {
    int max = *p;
    for (int i = 1; i < n; i++) {
        if (*(p + i) > max) {
            max = *(p + i);
        }
    }
    return max;
}

int findMin(int *p, int n) {
    int min = *p;
    for (int i = 1; i < n; i++) {
        if (*(p + i) < min) {
            min = *(p + i);
        }
    }
    return min;
}

double findAverage(int *p, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(p + i);
    }
    return (double)sum / n;
}

int countAbove(int *p, int n, double avg) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(p + i) > avg) {
            count++;
        }
    }
    return count;
}

void reverseArray(int *p, int n) {
    int *start = p;
    int *end = p + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (*(p + i) == key) {
            return i;
        }
    }
    return -1;
}