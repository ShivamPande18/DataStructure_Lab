#include<stdio.h>

int main()
{
    int n;
    printf("Enter the length of array: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter array elements: \n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int low = arr[j-1];
            int high = arr[j];

            if(low>high)
            {
                arr[j-1] = high;
                arr[j] = low;
            }
        }
    }

    printf("The sorted array is\n");

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}

