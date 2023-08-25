//Only sparse matrix is implemented not transpose

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

//    for(int i=0; i< sparseSize; i++)
//    {
//        int temp = arr[i][0];
//        arr[i][0] = arr[i][1];
//        arr[i][1] = temp;
////        if(i>0)
////        {
////            if(arr[i-1][0]>arr[i][0])
////            {
////
////            }
////        }
//    }

    for(int i=0; i<sparseSize; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ",arr[i][j]);

        }
        printf("\n");
    }

//    int spInd=0;
//
//    for(int i=0; i< ROW; i++)
//    {
//        for(int j=0; j<COL; j++)
//        {
//            if(i == arr[spInd][0] && j == arr[spInd][1])
//            {
//                printf("%d ",arr[spInd][2]);
//                spInd++;
//            }
//            else
//            {
//                printf("%d ",0);
//            }
//        }
//        printf("\n");
//    }


    return 0;
}
