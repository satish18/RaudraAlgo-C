#include <stdio.h>
#include <stdlib.h>
#define TOTAL_STATIONS 4
#define min(a, b) (a < b? a: b)

int assemblyLine(int arr[][TOTAL_STATIONS], int time[][TOTAL_STATIONS], int *entryTimes,
	int *exitTimes)
{
	int temp1[TOTAL_STATIONS], temp2[TOTAL_STATIONS], index;

	temp1[0] = entryTimes[0] + arr[0][0];
	temp2[0] = entryTimes[0] + arr[1][0];
	for(index = 1; index < TOTAL_STATIONS; index++)
	{
		temp1[index] = min(temp1[index-1] + arr[0][index], 
			temp2[index-1] + time[1][index] + arr[0][index]);
		temp2[index] = min(temp2[index-1] + arr[1][index], 
			temp1[index-1] + time[0][index] + arr[1][index]);
	}	
	return min(temp1[TOTAL_STATIONS-1] + exitTimes[0], 
		temp2[TOTAL_STATIONS-1] + exitTimes[1]);
} 

int main()
{
	int arr[][TOTAL_STATIONS] = {{5, 6, 4, 3}, {3, 11, 2, 5}};
	int time[][TOTAL_STATIONS] = {{1, 8, 5, 6}, {1, 10, 3, 9}};
	int entryTimes[] = {11, 13};
	int exitTimes[]	= {19, 8};
	printf("Minimum time = %d", assemblyLine(arr, time, entryTimes, exitTimes));
}