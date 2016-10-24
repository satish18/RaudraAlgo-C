#include<stdio.h>
  
void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
  
void minHeapify(int arr[], int size, int index)
{
    int left = 2*index+1;
    int right = 2*index+2;
    int smallest = index;
    if(left<size && arr[left]<arr[smallest])
        smallest = left;
    if(right<size && arr[right]<arr[smallest])
        smallest = right;
    if(smallest!=index)
    {
        swap(&arr[index], &arr[smallest]);
        minHeapify(arr, size, smallest);
    }     
}
  
  
void buildMinHeap(int arr[], int size) {
    for(int i=size/2; i>=0; i--)
        minHeapify(arr, size, i);         
}  

void printKElements(int minHeap[], int k)
{

    // print k-largest elements
    for(int i=0; i<k; i++)
    	printf("%d\t", minHeap[i]);
}
  
void kLargestElements(int arr[], int size, int k)
{
    buildMinHeap(arr, k);
    for(int i=k; i<size; i++)
    {
        if(arr[i] > arr[0])
        {
            arr[0] = arr[i];
            minHeapify(arr, k, 0);
        }
    }
    printKElements(arr, k);
}
  
  
int main() {
    int arr[] = {16, 8, 18, 4, 12, 9, 5, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    kLargestElements(arr, size, k);
    return 0;
}