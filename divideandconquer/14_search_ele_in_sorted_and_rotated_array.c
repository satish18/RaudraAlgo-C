#include <stdio.h>
#include <stdlib.h>

int searchInSortedRotatedArray(int *arr, int start, int end, int key)
{
    if (start > end) return -1; 
    int middle = (start + end)/2;
    if (arr[middle] == key) return middle;
 
    if (arr[start] <= arr[middle])
        return (key >= arr[start] && key <= arr[middle])? searchInSortedRotatedArray(arr, start, middle-1, key):
    searchInSortedRotatedArray(arr, middle+1, end, key);
    return (key >= arr[middle] && key <= arr[end])? searchInSortedRotatedArray(arr, middle+1, end, key):
    searchInSortedRotatedArray(arr, start, middle-1, key); 
}
 
int main()
{
    int *arr, size, key, index;
    printf("Enter size of an array\n");
    scanf("%d", &size);
    //allocate memory for array
    arr = (int *)malloc(size * sizeof(int));

    printf("Enter Array elements ");
    for(index = 0; index < size; index++)
        scanf("%d", &arr[index]);
    printf("Enter key to search in array\n");
    scanf("%d", &key);
    index = searchInSortedRotatedArray(arr, 0, size-1, key);
    if( index < 0)
        printf("Key not found\n");
    else
        printf("Key found at Index = %d\n", index);
    return 0;
}