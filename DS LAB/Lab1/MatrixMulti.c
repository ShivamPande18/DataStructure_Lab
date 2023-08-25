#include <stdio.h>

int main()
{
    int i, j, k, l;
    int matA[100][100], matB[100][100], matC[100][100];

    printf("Enter the number of rows and columns for matrices A:\n");
    scanf("%d %d", &i, &j);

    printf("Enter the number of rows and columns for matrices B:\n");
    scanf("%d %d", &k, &l);

    if (k != j)
    {
        printf("Wrong dimentions");
        return 0;
    }

    printf("Enter the elements of the matrix A:\n");
    for (int x = 0; x < i; x++)
    {
        for (int y = 0; y < j; y++)
        {
            scanf("%d", &matA[x][y]);
        }
    }



    printf("Enter the elements of the matrix B:\n");
    for (int x = 0; x < k; x++)
    {
        for (int y = 0; y < l; y++)
        {
            scanf("%d", &matB[x][y]);
        }
    }

    for (int m = 0; m < i; m++)
    {
        for (int m2 = 0; m2 < l; m2++)
        {
            matC[m][m2] = 0;
            for (int n = 0; n < j; n++)
            {
                matC[m][m2] += matA[m][n] * matB[n][m2];
            }
        }
    }

    printf("%d",matC[0][0]);

    for(int x=0; x< i ; x++)
    {

        for(int y=0; y<l; y++)
        {
            printf("%d ",matC[x][y]);
        }
        printf("\n");
    }

    return 0;
}
