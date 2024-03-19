#include <stdio.h>
#include <math.h> // For M_PI and pow

#define M_PI 3.1415 // Defining the value of PI

#define SIZE 5 // Defining the size of the 2D array

// Function prototypes
double calculateArea(double radius);
double calculatePerimeter(double radius);

int main()
{
    double radii[SIZE][SIZE];                   // 2D array for storing radii
    FILE *file = fopen("circle_data.txt", "w"); // Open file for writing

    // Check if the file is successfully opened
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Heading for the file
    fprintf(file, "Serial No.\tRadius\t\tArea\t\t\tPerimeter\n");

    // Fill the array with user inputs and write to file
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("Enter radius for element [%d][%d]: ", i, j);
            scanf("%lf", &radii[i][j]); // Store user input in the array
            // Calculate area and perimeter
            double area = calculateArea(radii[i][j]);
            double perimeter = calculatePerimeter(radii[i][j]);
            // Write data to the file
            fprintf(file, "%d\t\t%.2lf\t\t%.2lf\t\t%.2lf\n", i * SIZE + j + 1, radii[i][j], area, perimeter);
        }
    }

    // Close the file
    fclose(file);

    // Print the 2D array of radii and their corresponding areas
    printf("\nRadius and Corresponding Areas:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("[%.2lf, %.2lf] ", radii[i][j], calculateArea(radii[i][j]));
        }
        printf("\n");
    }

    return 0;
}

// Function to calculate the area of a circle
double calculateArea(double radius)
{
    return pow(radius, 2) * M_PI;
}

// Function to calculate the perimeter of a circle
double calculatePerimeter(double radius)
{
    return 2 * M_PI * radius;
}

// #include <stdio.h>

// #include <math.h>

// #include <stdlib.h>

// #define PI acos(-1) // Value of PI

// #define SIZE 5 // Size of 2D array

// // Function to calculate area of circle
// double calculateArea(int r)
// {
//     return PI * r * r;
// }

// // Function to calculate perimeter of circle
// double calculatePerimeter(int r)
// {
//     return 2 * PI * r;
// }

// int main()
// {
//     int radius[SIZE][SIZE]; // 2D array to store radius values

//     double area[SIZE][SIZE]; // 2D array to store area values

//     FILE *file = fopen("output.txt", "w"); // Open file in write mode

//     fprintf(file, "Serial No.\tRadius\tArea\tPerimeter\n"); // Write header to file

//     // Get radius values from user and calculate area and perimeter
//     for (int i = 0; i < SIZE; i++)

//         for (int j = 0; j < SIZE; j++)
//         {
//             printf("Enter radius for element [%d][%d]: ", i, j);

//             scanf("%d", &radius[i][j]);

//             area[i][j] = calculateArea(radius[i][j]);

//             double perimeter = calculatePerimeter(radius[i][j]);

//             fprintf(file, "%d\t\t\t%d\t\t%.2f\t%.2f\n", i * SIZE + j + 1, radius[i][j], area[i][j], perimeter);
//             // Write to file in tabular format
//         }

//     fclose(file); // Close file

//     printf("\nRadius and Area values:\n\n");

//     for (int i = 0; i < SIZE; i++)

//         for (int j = 0; j < SIZE; j++)

//             printf("Radius: %d, Area: %.2f\n", radius[i][j], area[i][j]); // Print radius and area values

//     printf("\n");

//     return 0;
// }

// #include <stdio.h>

// int i = 10; // Global variable

// void function1()
// {
//     int i = 20; // Local variable in function1

//     printf("%d\n", i);
// }

// void function2()
// {
//     printf("%d\n", i);
// }

// int main()
// {
//     int x = 30; // Local variable in main

//     printf("%d\n", x); // result will be 30

//     function1(); // Call function1 - result will be 20 (local variable)

//     function2(); // Call function2 - result will be 10 (global variable)

//     printf("%d\n", i);

//     {
//         int i = 7, j = 8;

//         printf("%d %d\n", i, j); // result will be 7 8 (local variables)
//         {
//             int i = 5; // Local variable in inner block

//             printf("%d %d\n", i, j); // result will be 5 8 (local variable)
//         }

//         printf("%d\n", i); // result will be 7 (local variable)
//     }

//     printf("%d\n", i); // result will be 10 (global variable)

//     return 0;
// }