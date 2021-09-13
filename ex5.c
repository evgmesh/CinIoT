/* Evgenii Meshcheriakov. Excercise 5 */

#include <stdio.h>
#include<string.h>

#define ROWS 3
#define COLS 3
#define VECT 1

int enter(int matr[][COLS], int row, int col);
int printer(int matr[][COLS], int row, int col);
void multiply(int matr[][COLS], int vector[][COLS], int result[][COLS]);

int main(void)
{
    int vector[VECT][COLS] = {};
    int inMatr[ROWS][COLS] = {};
    int result[VECT][COLS] = {};
    int row, col;

    printf("Enter elements of the first matrix %dx%d, please\n", ROWS, VECT);
    enter(vector, VECT, COLS);
    printf("Enter elements of the second matrix %dx%d, please\n", ROWS, COLS);
    enter(inMatr, ROWS, COLS);

    multiply(inMatr, vector, result);

    printf("Initial values of the vector are:\n");
    printer(vector, VECT, COLS);
    printf("Initial values of the matrix are:\n");
    printer(inMatr, ROWS, COLS);
    printf("Result vector after multiplication:\n");
    printer(result, VECT, COLS);

    return 0;
}

void multiply(int matr[][COLS], int vector[][COLS], int result[][COLS])
{
    for (int i = 0; i<ROWS; i++) {
        for(int j = 0; j<VECT; j++) {
            for(int k = 0; k < COLS; k++) {
                result[j][i] += matr[i][k] * vector[j][k];
            }
        }
    }
}

int enter(int matr[][COLS], int row, int col)
{
    int elements = 0;
    for (int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            elements++;
            printf("Number %d/%d is: ", elements, row*col);
            scanf("%d", &matr[i][j]);
        }
    }
    return 0;
}

int printer(int matr[][COLS], int row, int col)
{
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
    return 0;
}