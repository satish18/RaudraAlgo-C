			// Convert Minheap to Maxheap

#include <stdio.h>
#include <stdlib.h>

void swap(int heap[], int a, int b)
{
	int temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void MaxHeapify(int heap[], int index, int size)
{
	int left = 2*index + 1, right=2*index+2, greatest=index;
	greatest = (left<size && heap[left]>heap[index])? left: index; 
	if (right < size && heap[right]>heap[greatest])
		greatest = right;
	if (greatest != index)
	{
		swap(heap, index, greatest);
		MaxHeapify(heap, greatest, size);
	}

}

void convertToMaxHeap(int heap[], int size)
{
	int index;
	for(index = (size/2)-1; index >= 0; index--)
		MaxHeapify(heap, index, size);
}

void printMaxHeap(int heap[], int size)
{
	int index;
	for(index = 0; index < size; index++)
		printf("%d\t", heap[index]);
}

int main()
{
	int *heap, size, index;
	printf("Enter size of the heap");
	scanf("%d", &size);
	//allocate memory
	heap = (int *)malloc(sizeof(int) * size);
	printf("Enter elements to heap\n");
	for(index = 0; index< size; index++)
		scanf("%d", &heap[index]);
	convertToMaxHeap(heap, size);
	printMaxHeap(heap, size);
	return 0;
}