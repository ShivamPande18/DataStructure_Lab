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

    int src;
    int flag = 0;

    printf("Enter the search term: ");
    scanf("%d",&src);

    for(int i=0;i<n;i++)
    {
        if(src == arr[i])
        {
            printf("Found");
            flag = 1;
            break;
        }
    }

    if(flag == 0) printf("Not Found");

    return 0;
}
