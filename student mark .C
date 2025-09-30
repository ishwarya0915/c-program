#include <stdio.h>

#define MAX 100   // Maximum number of students
#define SUBJECTS 3 // Number of subjects

// Structure to store student details
struct Student {
    char name[50];
    int rollNo;
    float marks[SUBJECTS];
    float total;
    float percentage;
};

int main() {
    struct Student s[MAX];
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student details
    for (i = 0; i < n; i++) {
        s[i].total = 0; // Initialize total marks to zero
        
        printf("\nEnter details for Student %d\n", i + 1);
        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name); // Take full name including spaces
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollNo);

        for (j = 0; j < SUBJECTS; j++) {
            printf("Enter marks in subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        // Calculating percentage
        s[i].percentage = s[i].total / SUBJECTS;
    }

    // Display student details with results
    printf("\n%-5s %-20s %-10s %-10s %-10s\n", "Roll", "Name", "Total", "Percent", "Result");
    for (i = 0; i < n; i++) {
        printf("%-5d %-20s %-10.2f %-10.2f ",
               s[i].rollNo, s[i].name, s[i].total, s[i].percentage);

        if (s[i].percentage >= 40)
            printf("Pass\n");
        else
            printf("Fail\n");
    }

    return 0;
}
