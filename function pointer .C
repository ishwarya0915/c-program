#include <stdio.h>

// Function prototypes
float add(float a, float b) { return a + b; }
float sub(float a, float b) { return a - b; }
float mul(float a, float b) { return a * b; }
float divide(float a, float b) { return (b != 0) ? (a / b) : 0; }

int main() {
    // Array of function pointers
    float (*operations[])(float, float) = {add, sub, mul, divide};
    char *opNames[] = {"Addition", "Subtraction", "Multiplication", "Division"};

    int choice;
    float num1, num2, result;

    while (1) {
        printf("\n=== Calculator using Function Pointers ===\n");
        for (int i = 0; i < 4; i++)
            printf("%d. %s\n", i + 1, opNames[i]);
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);

        if (choice == 4 && num2 == 0) {
            printf("Error! Division by zero.\n");
            continue;
        }

        // Call the chosen function using function pointer array
        result = operations[choice - 1](num1, num2);

        printf("Result: %.2f\n", result);
    }

    return 0;
}
