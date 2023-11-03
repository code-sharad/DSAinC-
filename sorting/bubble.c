// In this algorithm, 

// traverse from left and compare adjacent elements and the higher one is placed at right side. 
// In this way, the largest element is moved to the rightmost end at first. 
// This process is then continued to find the second largest and place it and so on until the data is sorted.

// Time Complexity: O(N^2)
// Auxiliary Space: O(1)

// Advantages of Bubble Sort:
// Bubble sort is easy to understand and implement.
// It does not require any additional memory space.
// It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.
// Disadvantages of Bubble Sort:
// Bubble sort has a time complexity of O(N^2) which makes it very slow for large data sets.
// Bubble sort is a comparison-based sorting algorithm, which means that it requires a comparison operator to determine the relative order of elements in the input data set. It can limit the efficiency of the algorithm in certain cases.


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
        for (j = 0; j < size - i - 1; j++)
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