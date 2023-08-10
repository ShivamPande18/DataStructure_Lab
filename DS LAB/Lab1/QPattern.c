#include<stdio.h>

int main()
{
    int row;
    int col;

    printf("Enter size of Q:\n");
    scanf("%d",&row);

    col = row;

    int qPntX = (row)/2;
    int qPntY = (col)/2;

    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0 || i == row-1)
            {
                printf("*");
            }
            else
            {
                if(j==0 || j==col-1)
                {
                    printf("*");

                }
                else if(i == qPntX && j == qPntY)
                {
                    printf("*");
                    qPntX++;
                    qPntY++;
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }


    for(int i=0;i<(row/2)-1;i++)
    {
        for(int j=0;j<=qPntX;j++)
        {
            printf(" ");
        }
        printf("*\n");
        qPntX++;

    }

    return 0;
}
