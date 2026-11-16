#include <stdio.h>
#include <stdlib.h>

void readMarks(int *m1, int *m2, int *m3);
void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest);
void swapMarks(int *a, int *b);
void addGraceMarks(int *mark, int *grace);
void findGrade(double avg, char *grade, char *remarks);
void incrementByValue(int x);
void incrementByReference(int *x);

int main() {
    int num_students = 5;

    printf("=== SEMESTER RESULT PROCESSING SYSTEM ===\n\n");
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-8s %-20s\n", "Student", "Sub 1", "Sub 2", "Sub 3", "Total", "Average", "Grade", "Remarks");
    for (int i = 0; i < 86; i++) {
        printf("-");
    }
    printf("\n");

    for (int i = 1; i <= num_students; i++) {
        int m1, m2, m3;
        int total, highest, lowest;
        double average;
        char grade;
        char remarks[30];

        printf("\nEntering marks for Student %d:\n", i);
        readMarks(&m1, &m2, &m3);

        int graceGiven = 0;
        addGraceMarks(&m1, &graceGiven);
        addGraceMarks(&m2, &graceGiven);
        addGraceMarks(&m3, &graceGiven);

        calculateStats(m1, m2, m3, &total, &average, &highest, &lowest);
        findGrade(average, &grade, remarks);

        printf("S%-9d %-10d %-10d %-10d %-10d %-10.1f %-8c %-20s\n", i, m1, m2, m3, total, average, grade, remarks);
    }

    printf("\n\n=== COMPARISON DEMO: PASS BY VALUE VS REFERENCE ===\n");
    int testVar = 10;
    printf("Initial value of testVar: %d\n", testVar);

    incrementByValue(testVar);
    printf("After incrementByValue(testVar), value is: %d\n", testVar);

    incrementByReference(&testVar);
    printf("After incrementByReference(&testVar), value is: %d\n", testVar);

    return 0;
}

void readMarks(int *m1, int *m2, int *m3) {
    do {
        printf("  Mark 1 (0-100): ");
        scanf("%d", m1);
    } while (*m1 < 0 || *m1 > 100);

    do {
        printf("  Mark 2 (0-100): ");
        scanf("%d", m2);
    } while (*m2 < 0 || *m2 > 100);

    do {
        printf("  Mark 3 (0-100): ");
        scanf("%d", m3);
    } while (*m3 < 0 || *m3 > 100);
}

void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest) {
    *total = m1 + m2 + m3;
    *average = (double)(*total) / 3.0;

    *highest = m1;
    if (m2 > *highest) *highest = m2;
    if (m3 > *highest) *highest = m3;

    *lowest = m1;
    if (m2 < *lowest) *lowest = m2;
    if (m3 < *lowest) *lowest = m3;
}

void swapMarks(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void addGraceMarks(int *mark, int *grace) {
    if (*mark >= 35 && *mark <= 39) {
        *grace = 40 - *mark;
        *mark = 40;
    }
}

void findGrade(double avg, char *grade, char *remarks) {
    if (avg >= 75.0) {
        *grade = 'A';
        char *s = "Excellent";
        int i = 0;
        while (s[i] != '\0') {
            remarks[i] = s[i];
            i++;
        }
        remarks[i] = '\0';
    } else if (avg >= 50.0) {
        *grade = 'B';
        char *s = "Good";
        int i = 0;
        while (s[i] != '\0') {
            remarks[i] = s[i];
            i++;
        }
        remarks[i] = '\0';
    } else {
        *grade = 'F';
        char *s = "Needs Improvement";
        int i = 0;
        while (s[i] != '\0') {
            remarks[i] = s[i];
            i++;
        }
        remarks[i] = '\0';
    }
}

void incrementByValue(int x) {
    x++;
}

void incrementByReference(int *x) {
    (*x)++;
}
```[cite: 4]