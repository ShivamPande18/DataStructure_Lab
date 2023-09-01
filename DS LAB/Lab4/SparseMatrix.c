#include<stdio.h>

int row;
int col;
int sparseLen=0;

typedef struct
{
    int row;
    int col;
    int val;
} sparseSt;

int main()
{
    printf("Enter row:\n");
    scanf("%d",&row);
    printf("Enter col:\n");
    scanf("%d",&col);

    printf("Enter values:\n");

    int sparseMat[row][col];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int temp;
            scanf("%d",&temp);
            sparseMat[i][j] = temp;

            if(temp!=0) sparseLen++;
        }
    }

    sparseSt a[sparseLen+1];
    a[0].row = row;
    a[0].col = col;
    a[0].val = sparseLen;

    int ind=1;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int temp = sparseMat[i][j];
            if(temp!=0)
            {
                a[ind].row = i;
                a[ind].col = j;
                a[ind].val = temp;
                ind++;
            }
        }
    }
    printf("Sparse Matrix struct:\n")

    for(int i=0;i<=sparseLen;i++)
    {
        printf("%d %d %d\n",a[i].row, a[i].col, a[i].val);
    }


    return 0;
}
