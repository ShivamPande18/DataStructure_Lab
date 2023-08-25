#include <stdio.h>

int main()
{
    int rows, cols;

    printf("Enter the number of rows and columns for matrices A and B:\n");
    scanf("%d %d", &rows, &cols);

    int matA[100][100], matB[100][100], matC[100][100];

    printf("Enter the elements of the matrix A:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Enter the elements of the matrix B:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matB[i][j]);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matC[i][j] = (matA[i][j] > matB[i][j]) ? matA[i][j] : matB[i][j];
        }
    }

    printf("Matrix C = :\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matC[i][j]);
        }
        printf("\n");
    }

    return 0;
}
