#include <stdio.h>

void selectionSort(int arr[], int i, int j, int size, int flag)

{
    int temp;
    if (i < size - 1)
    {
        if(flag) j = i + 1;
        if (j < size)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            selectionSort(arr, i, j + 1, size, 0);
        }
        selectionSort(arr, i + 1, 0, size, 1);
    }
}

int main()
{
    int arr[100], size, temp;

    printf("Enter the size of the array:\n");
    scanf("%d", &size);

    printf("Enter the elements in array:\n");
    for (int i = 0; i < size; i++) 
        scanf("%d", &arr[i]);

    selectionSort(arr, 0, 0, size, 1);

    printf("The sorted array in ascending order is\n");
    for (int i = 0; i < size; i++) 
        printf("%d  ", arr[i]);

    return 0;
}
