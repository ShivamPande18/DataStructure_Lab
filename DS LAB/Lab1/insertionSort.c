#include <stdio.h>

int main()
{
    int n;
    printf("Enter the length of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: \n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    printf("The sorted array is\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
