//Values are taken by default. Need to add user inputs. Rest all is done

#include<stdio.h>
#define ROW 4
#define COL 5


int sparse[ROW][COL] = {
{0, 0, 7, 0, 3},
{0, 9, 0, 7, 0},
{6, 0, 0, 0, 0},
{0, 4, 0, 0, 0}
};

int main()
{
    int sparseSize = 0;
    int arr[100][3] = {};

    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(sparse[i][j] != 0)
            {
//                printf("%d %d %d \n",i,j,sparse[i][j]);
                arr[sparseSize][0] = i;
                arr[sparseSize][1] = j;
                arr[sparseSize][2] = sparse[i][j];
                sparseSize++;
            }
        }

    }

    for(int i=0; i< sparseSize; i++)
    {
        int temp = arr[i][0];
        arr[i][0] = arr[i][1];
        arr[i][1] = temp;
    }

    for(int i=0; i<sparseSize-1; i++)
    {
        for(int j=0; j<sparseSize-1; j++)
        {
            int low = arr[j][0]*10 + arr[j][1];
            int high = arr[j+1][0]*10 + arr[j+1][1];


            if(low>high)
            {
                int x1 = arr[j][0];
                int x2 = arr[j][1];
                int x3 = arr[j][2];

                int y1 = arr[j+1][0];
                int y2 = arr[j+1][1];
                int y3 = arr[j+1][2];

                arr[j][0] = y1;
                arr[j][1] = y2;
                arr[j][2] = y3;

                arr[j+1][0] = x1;
                arr[j+1][1] = x2;
                arr[j+1][2] = x3;
            }
        }
    }




    int spInd=0;

    for(int i=0; i< ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(i == arr[spInd][0] && j == arr[spInd][1])
            {
                printf("%d ",arr[spInd][2]);
                spInd++;
            }
            else
            {
                printf("%d ",0);
            }
        }
        printf("\n");
    }


    return 0;
}
