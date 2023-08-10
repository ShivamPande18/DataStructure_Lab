#include<stdio.h>

int main()
{
    int n;
    printf("Enter the length of array: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter sorted array elements: \n");

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

    int src;
    int flag = 0;

    printf("Enter the search term: ");
    scanf("%d",&src);

    int low = 0;
    int high = n;

    int mid = (low+high)/2;

    while(low<=high)
    {
        if(arr[mid]<src)
        {
            low = mid+1;
        }
        else if(arr[mid]>src)
        {
            high = mid-1;
        }
        else
        {
            printf("found");
            flag = 1;
            break;
        }

        mid = (low+high)/2;
    }

    if(flag == 0) printf("Not Found");

    return 0;
}
