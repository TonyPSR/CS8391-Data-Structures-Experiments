#include <stdio.h>
#include <stdlib.h>


int shellSort(int arr[], int n)
{
    int gap, i;
    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

void printArray(int arr[], int n)
{
    int i;
    for (i=0; i<n; i++)
        printf("%d, ", arr[i]);
}

int main()
{
    int arr[] = {12, 34, 54, 2, 3}, i;
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorting: \n");
    printArray(arr, n);

    shellSort(arr, n);

    printf( "\nArray after sorting: \n");
    printArray(arr, n);

    return 0;
}
