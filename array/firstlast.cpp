#include<iostream>
#include<vector>
using namespace std;

int first(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
 
        // Normal Binary Search Logic
        int mid = (low + high) / 2;
 
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
 
        // If arr[mid] is same as x, we
        // update res and move to the left
        // half.
        else {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}
 
/* If x is present in arr[] then returns
the index of LAST occurrence of x in
arr[0..n-1], otherwise returns -1 */
int last(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
 
        // Normal Binary Search Logic
        int mid = (low + high) / 2;
 
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
 
        // If arr[mid] is same as x, we
        // update res and move to the right
        // half.
        else {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}


int main(){
    int arr[] = {5,7,7,8,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << n << endl;
    // cout << "First Postion:" << firstAndLastPos(arr,size,8).at(0) <<endl;
    // cout << "Last Postion:" << firstAndLastPos(arr,size,8).at(0) << endl;
     int x = 8;
    cout << "First Occurrence = " << first(arr, x, n);
    cout << "\nLast Occurrence = " << last(arr, x, n);
}