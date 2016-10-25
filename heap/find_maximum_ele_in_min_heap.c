#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void MinHeapify(int *arr, int index, int size)
{
	int left = 2*index + 1;
	int right = 2*index + 2;
	int smallest = index;

	if (left < size && arr[left] < arr[index])
        smallest = left;
    if (right < size && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != index)
    {
        swap(&arr[index], &arr[smallest]);
        MinHeapify(arr, index, smallest);
    }
}

void buildMinHeap(int *arr, int size)
{
	for(int index = size/2 -1; index >= 0; index-- )
		MinHeapify(arr, index, size);
}

int findMaxElement(int *arr, int size)
{
	int Max = INT_MIN;
	for(int index = (size + 1)/2; index < size; index++)
		if(arr[index] > Max)
			Max = arr[index];
	return Max;
}


int main()
{
	int *arr, size, index;
	printf("Enter size of heap\n");
	scanf("%d", &size);

	//allocate memory
	arr = (int *) malloc(sizeof(int) * size);

	printf("Enter elements in heap\n");
	for(index = 0; index < size; index++)
		scanf("%d", &arr[index]);

	//construct min-heap ( min-heapify)
	buildMinHeap(arr, size);

	//find max_element

	printf("Maximum element in Min-heap is = %d", findMaxElement(arr, size));


}