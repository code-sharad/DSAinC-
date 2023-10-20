#include <stdio.h>

void swap(int* current, int* previous){
    int temp = *previous;
    *previous = *current;
    *current = temp;
}

void bubbleSort(int arr[], int size)
{
    int i,j;
    for (i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j],&arr[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[7] = {32, 21, 54, 32, 65, 4, 1};
    printf("\n");
    printf("Before sorting: ");
    printArray(arr, 7);
    bubbleSort(arr, 7);
    printf("After sorting: ");
    printArray(arr, 7);
    printf("\n");
}