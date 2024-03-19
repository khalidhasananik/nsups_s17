#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#define PI acos(-1) // Value of PI

#define SIZE 5 // Size of 2D array

// Function to calculate area of circle
double calculateArea(int r)
{
    return PI * r * r;
}

// Function to calculate perimeter of circle
double calculatePerimeter(int r)
{
    return 2 * PI * r;
}

int main()
{
    int radius[SIZE][SIZE]; // 2D array to store radius values

    double area[SIZE][SIZE]; // 2D array to store area values

    FILE *file = fopen("output.txt", "w"); // Open file in write mode

    fprintf(file, "Serial No.\tRadius\tArea\tPerimeter\n"); // Write header to file

    // Get radius values from user and calculate area and perimeter
    for (int i = 0; i < SIZE; i++)

        for (int j = 0; j < SIZE; j++)
        {
            printf("Enter radius for element [%d][%d]: ", i, j);

            scanf("%d", &radius[i][j]);

            area[i][j] = calculateArea(radius[i][j]);

            double perimeter = calculatePerimeter(radius[i][j]);

            fprintf(file, "%d\t\t\t%d\t\t%.2f\t%.2f\n", i * SIZE + j + 1, radius[i][j], area[i][j], perimeter);
            // Write to file in tabular format
        }

    fclose(file); // Close file

    printf("\nRadius and Area values:\n\n");

    for (int i = 0; i < SIZE; i++)

        for (int j = 0; j < SIZE; j++)

            printf("Radius: %d, Area: %.2f\n", radius[i][j], area[i][j]); // Print radius and area values

    printf("\n");

    return 0;
}