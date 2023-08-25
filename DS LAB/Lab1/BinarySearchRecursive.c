#include <stdio.h>

int binarySearch(int arr[100], int lower, int upper, int src)
{
    if (upper >= lower)
    {
        int mid = lower + (upper - lower) / 2;
        if (arr[mid] == src) return mid;
        if (arr[mid] > src) return binarySearch(arr, lower, mid - 1, src);
        return binarySearch(arr, mid + 1, upper, src);
    }
    return -1;
}

int main()
{
    int n,src,arr[100];
    printf("Enter number of array Elements\n");
    scanf("%d",&n);

    printf("Enter array elements\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter term to search\n");
    scanf("%d",&src);

    int result = binarySearch(arr, 0, n - 1, src);
    (result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result);
    return 0;
}
