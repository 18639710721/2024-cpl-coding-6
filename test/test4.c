#include <stdio.h>

/*
 * When to Use Macrosls
 * 
Avoid magic numbers: Use macros to define constants like PI, MAX_SIZE.
Reusable logic: For simple inline expressions or logic, macros reduce repetition.
Platform-specific code: Conditional macros like _WIN32 make the code portable.
 */

// 1.Object-like Macros
// Used to define constants or replace names with fixed values.
#define PI 3.14159
#define Y_SIZE 20

// 2.Function-like Macros
// Used to define reusable expressions or lightweight "functions"
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 3.Conditional Compilation with Macros
// Used to compile code selectively based on conditions.
#define DEBUG 1


int main() {
    printf("The value of PI is: %.2f\n", PI);
    printf("The Y_SIZE is: %d\n", Y_SIZE);

    int num = 5;
    printf("Square of %d is: %d\n", num, SQUARE(num));
    printf("Maximum of %d and %d is: %d\n", 10, 20, MAX(10, 20));

#if DEBUG
    printf("Debugging is enabled\n");
#else
    printf("Debugging is disabled\n");
#endif

    // Using Predefined Macros
    // C has several predefined macros useful for debugging or logging
    printf("This file is: %s\n", __FILE__); //  The current file name.
    printf("This line is: %d\n", __LINE__); // The current line number.
    printf("Compiled on: %s at %s\n", __DATE__, __TIME__); // the date and time of compilation.

    return 0;

}
