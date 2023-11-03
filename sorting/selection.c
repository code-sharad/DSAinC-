
// Selection sort is a simple and efficient sorting algorithm that works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the list and moving it to the sorted portion of the list. 

// Complexity Analysis of Selection Sort
// Time Complexity: The time complexity of Selection Sort is O(N2) as there are two nested loops:

// One loop to select an element of Array one by one = O(N)
// Another loop to compare that element with every other Array element = O(N)
// Therefore overall complexity = O(N) * O(N) = O(N*N) = O(N2)
// Auxiliary Space: O(1) as the only extra memory used is for temporary variables while swapping two values in Array. The selection sort never makes more than O(N) swaps and can be useful when memory writing is costly. 

// Advantages of Selection Sort Algorithm
// Simple and easy to understand.
// Works well with small datasets.
// Disadvantages of the Selection Sort Algorithm
// Selection sort has a time complexity of O(n^2) in the worst and average case.
// Does not work well on large datasets.
// Does not preserve the relative order of items with equal keys which means it is not stable.

#include<stdio.h>

void selection(int arr[],int size){
    int i,j,min,temp;
    for(i=0;i<size-1;i++){
        min=i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

int main(){
    int arr[]={5,4,3,2,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    selection(arr,size);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

}