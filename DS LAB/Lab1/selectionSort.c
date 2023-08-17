#include<stdio.h>

int main()
{
    int n;
    printf("Enter the length of array: ");
    scanf("%d",&n);

    int arr[n];
    int minInd = 0;

    printf("Enter array elements: \n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        minInd = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minInd])
            {
                minInd = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = temp;

        printf("\n");
    }

    printf("The sorted array is\n");

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}


